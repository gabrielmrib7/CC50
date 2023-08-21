function getProjects(){
    const urlGitHub = 'https://api.github.com/users/gabrielmrib7/repos'
    var loadingElement = document.getElementById('loading')

    fetch(urlGitHub, {
        method: 'GET',
    })
    .then((response) => response.json())
    .then((response) => {
        showProjects(response)
        loadingElement.style.display = 'none'
    })
    .catch((e)=>{console.log(e)})
}

function showProjects(data){
    var listElement = document.getElementById('projetos')
    for(let i = 0; i < data.length; i++)
    {
        let div = document.createElement("div")
        let a = document.createElement("a")
        a.href = data[i]['clone_url']
        a.target = '_blank'
        a.title = data[i]['description']
        let linkText = document.createTextNode(data[i]['name'])
        a.appendChild(linkText)
        div.appendChild(a)
        listElement.appendChild(div)
    }
}

getProjects()