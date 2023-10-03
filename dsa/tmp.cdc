pub contract SupplyChain {

    // Producer structure
    pub struct Producer {
        pub var id: Address
        pub var trucks: [Address]
        pub var truckDetails: [String]
    }

    // Warehouse structure
    pub struct Warehouse {
        pub var id: Address
        pub var isRetailer: Bool
        pub var trucks: [Address]
        pub var truckDetails: [String]
    }

    // ProductInfo structure
    pub struct ProductInfo {
        pub var producer: Address
        pub var name: String
        pub var price: String
        pub var imageURL: String
        pub var isPerishable: Bool
        pub var params: [String]
        pub var minValues: [Int]
        pub var maxValues: [Int]
    }

    // ProductLot structure
    pub struct ProductLot {
        pub var productId: UInt
        pub var productLotId: UInt
        pub var producerAddress: Address
        pub var quantity: UInt
        pub var createdAt: UInt
        pub var sourceFactoryName: String
        pub var sourceFactoryLocation: String
        pub var rejected: Bool
        pub var rejectedMessage: String
    }

    // Checkpoint structure
    pub struct Checkpoint {
        pub var inTime: UInt
        pub var outTime: UInt
        pub var warehouse: Warehouse
        pub var in_temperature: Int
        pub var in_humidity: Int
        pub var out_temperature: Int
        pub var out_humidity: Int
        pub var truckAssigned: Address
        pub var polledTemperatures: [Int]
        pub var polledHumidity: [Int]
        pub var polledTimes: [UInt]
        pub var validities: [Bool]
    }

    // Producers mapping
    pub var producers: {Address: Producer}

    // Warehouses mapping
    pub var warehouses: {Address: Warehouse}

    // ProductsInfo mapping
    pub var productsInfo: {Address: [ProductInfo]}

    // ProductLots mapping
    pub var productLots: {Address: [ProductLot]}

    // Checkpoints mapping
    pub var checkpoints: {String: [Checkpoint]}

    // WarehouseProductLots mapping
    pub var warehouseProductLots: {Address: [String]}

    // Modifier: Must be a producer
    pub fun mustBeProducer(address: Address) {
        pre {
            producers[address] != nil: "Invalid producer"
        }
    }

    // Modifier: Must be a warehouse
    pub fun mustBeWarehouse(address: Address) {
        pre {
            warehouses[address] != nil: "Invalid warehouse"
        }
    }

    // Function: Register producer
    pub fun registerProducer() {
        let address = getAccountAddress()
        let producer = Producer(
            id: address,
            trucks: [],
            truckDetails: []
        )
        producers[address] = producer
    }

    // Function: Register warehouse
    pub fun registerWarehouse(isRetailer: Bool) {
        let address = getAccountAddress()
        let warehouse = Warehouse(
            id: address,
            isRetailer: isRetailer,
            trucks: [],
            truckDetails: []
        )
        warehouses[address] = warehouse
    }

    // Function: Add truck
    pub fun addTruck(role: UInt, truck: Address, truckDetails: String) {
        let address = getAccountAddress()

        if role == 0 {
            producers[address].trucks.append(truck)
            producers[address].
            truckDetails.append(truckDetails)
} else if role == 1 {
warehouses[address].trucks.append(truck)
warehouses[address].truckDetails.append(truckDetails)
}
}

// Function: Add product info
pub fun addProductInfo(
    name: String,
    price: String,
    imageURL: String,
    isPerishable: Bool,
    params: [String],
    minValues: [Int],
    maxValues: [Int]
) {
    let address = getAccountAddress()

    let productInfo = ProductInfo(
        producer: address,
        name: name,
        price: price,
        imageURL: imageURL,
        isPerishable: isPerishable,
        params: params,
        minValues: minValues,
        maxValues: maxValues
    )

    if productsInfo[address] == nil {
        productsInfo[address] = []
    }

    productsInfo[address].append(productInfo)
}

// Function: Create product lot
pub fun createProductLot(
    productId: UInt,
    productLotId: UInt,
    producerAddress: Address,
    quantity: UInt,
    createdAt: UInt,
    sourceFactoryName: String,
    sourceFactoryLocation: String
) {
    let productLot = ProductLot(
        productId: productId,
        productLotId: productLotId,
        producerAddress: producerAddress,
        quantity: quantity,
        createdAt: createdAt,
        sourceFactoryName: sourceFactoryName,
        sourceFactoryLocation: sourceFactoryLocation,
        rejected: false,
        rejectedMessage: ""
    )

    if productLots[producerAddress] == nil {
        productLots[producerAddress] = []
    }

    productLots[producerAddress].append(productLot)
}

// Function: Assign product lot to warehouse
pub fun assignProductLotToWarehouse(
    producerAddress: Address,
    productLotId: UInt,
    warehouseAddress: Address
) {
    mustBeProducer(producerAddress)

    let productLot = productLots[producerAddress][productLotId]

    // Check if the warehouse exists
    pre {
        warehouses[warehouseAddress] != nil: "Warehouse does not exist"
    }

    // Check if the product lot is not already assigned to a warehouse
    pre {
        productLot.warehouse.id == nil: "Product lot already assigned to a warehouse"
    }

    let warehouse = warehouses[warehouseAddress]
    productLot.warehouse = warehouse

    if warehouseProductLots[warehouseAddress] == nil {
        warehouseProductLots[warehouseAddress] = []
    }

    warehouseProductLots[warehouseAddress].append(
        producerAddress.toHexString() ++ "_" ++ productLotId.toString()
    )
}

// Function: Check in at checkpoint
pub fun checkInAtCheckpoint(
    producerAddress: Address,
    productLotId: UInt,
    temperature: Int,
    humidity: Int,
    truckAssigned: Address
) {
    mustBeProducer(producerAddress)

    let productLot = productLots[producerAddress][productLotId]
    let productInfo = productsInfo[producerAddress][productLot.productId]

    pre {
        temperature >= productInfo.minValues[0]: "Min temp not met"
        temperature <= productInfo.maxValues[0]: "Max temp not met"
        humidity >= productInfo.minValues[1]: "Min humidity not met"
        humidity <= productInfo.maxValues[1]: "Max humidity not met"
    }

    let productLotIndex = productLots[producerAddress].indexOf(productLot)
    let checkpointIndex = checkpoints[
        producerAddress.toHexString() ++ "_" ++ productLotIndex.toString()
    ].length - 1

    let checkpoint: Checkpoint = checkpoints[
producerAddress.toHexString() ++ "_" ++ productLotIndex.toString()
][checkpointIndex]

    if checkpointIndex == 0 {
        // 0th Checkout from producer only
        pre {
            producerAddress == getAccountAddress(): "Only producer can checkout factory"
            producers[producerAddress].trucks[_truckAssignedIdx] == truckAssigned: "Use own trucks for checkout"
        }
    } else {
        pre {
            warehouses[getAccountAddress()].id != nil: "Warehouse does not exist"
            !warehouses[getAccountAddress()].isRetailer: "Retailers can't checkout"
            checkpoint.warehouse.id == getAccountAddress(): "Can't checkout else's checkpoint"
            warehouses[getAccountAddress()].trucks[_truckAssignedIdx] == truckAssigned: "Use own trucks for checkout"
        }
    }

    pre {
        checkpoint.outTime == nil: "Already checked out"
    }

    checkpoint.outTime = getCurrentBlock().timestamp
    checkpoint.out_temperature = temperature
    checkpoint.out_humidity = humidity
    checkpoint.truckAssigned = truckAssigned
}

// Function: Poll checkpoint
pub fun poll(
    producerAddress: Address,
    lotId: UInt,
    productLotId: String,
    temperature: Int,
    humidity: Int
) {
    let productLot = productLots[producerAddress][lotId]
    let productInfo = productsInfo[producerAddress][productLot.productId]

    let targetCheckpoints = checkpoints[productLotId]
    let checkpointIndex = targetCheckpoints.length - 1

    pre {
        targetCheckpoints[checkpointIndex].outTime != nil: "Reached destination"
        targetCheckpoints[checkpointIndex].truckAssigned == getAccountAddress(): "Only assigned truck can poll !"
    }

    let isValid = temperature >= productInfo.minValues[0] &&
        humidity >= productInfo.minValues[1] &&
        temperature <= productInfo.maxValues[0] &&
        humidity <= productInfo.maxValues[1]

    let checkpoint = targetCheckpoints[checkpointIndex]

    checkpoint.polledTemperatures.append(temperature)
    checkpoint.polledHumidity.append(humidity)
    checkpoint.polledTimes.append(getCurrentBlock().timestamp)
    checkpoint.validities.append(isValid)
}
}