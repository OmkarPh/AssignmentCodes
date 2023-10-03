const signup = (event) => {
    event.preventDefault()
    console.log(event.target.name.value)
    console.log(event.target.gender.value)
    console.log(event.target.dob.value)
    console.log(event.target.nationality.value)
    console.log(event.target.agreeTerms.value)
    var name = event.target.name.value
    const url = "/dashboard.html?name="+name
    window.location.href = url
}