const clickme = (name) => {
    alert(name)
}

// clickme()

const add = () => {
    const num1 = parseInt(document.getElementById('num1').value)
    const num2 = parseInt(document.getElementById('num2').value)
    const result = num1 + num2
    document.getElementById('result').value = result
}