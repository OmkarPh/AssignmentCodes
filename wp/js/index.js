const onSubmitHanlder = (event) => {
    event.preventDefault();
    console.log("Hello");
    console.log(event.target.branch.value);
}