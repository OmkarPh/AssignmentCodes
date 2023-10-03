const ObjectId = require('mongoose').Types.ObjectId;

function isValidObjectId(id){
    
    if(ObjectId.isValid(id)){
        if((String)(new ObjectId(id)) === id)
            return true;
        return false;
    }
    return false;
}

const testStrings = [ "594ced02ed345b2b049222c5",  "geeks",  "toptoptoptop",  "geeksfogeeks"];

for(const testcase of testStrings){

    if(isValidObjectId(testcase))
        console.log(testcase + " is a valid MongodbID");
    else
        console.log(testcase + " is a valid MongodbID");

}