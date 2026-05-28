function addTask(){

let title=document.getElementById("title").value;
let description=document.getElementById("description").value;

if(title===""){

alert("Please enter task title");
return;
}

let date=new Date();

let time=date.toLocaleString();

let task=document.createElement("div");

task.classList.add("task");

task.innerHTML=`

<h3>${title}</h3>

<p>${description}</p>

<div class="time">
Added: ${time}
</div>

<div class="actions">

<button class="complete"
onclick="completeTask(this)">
Complete
</button>

<button class="edit"
onclick="editTask(this)">
Edit
</button>

<button class="delete"
onclick="deleteTask(this)">
Delete
</button>

</div>

`;

document.getElementById("pendingList")
.appendChild(task);

document.getElementById("title").value="";
document.getElementById("description").value="";

}


function completeTask(button){

let task=button.parentElement.parentElement;

let completedTime=document.createElement("div");

completedTime.classList.add("time");

completedTime.innerHTML=
"Completed: "+
new Date().toLocaleString();

task.appendChild(completedTime);

button.remove();

document.getElementById(
"completedList"
).appendChild(task);

}


function editTask(button){

let task=button.parentElement.parentElement;

let title=task.querySelector("h3");

let desc=task.querySelector("p");

let newTitle=prompt(
"Edit title",
title.innerText
);

let newDesc=prompt(
"Edit description",
desc.innerText
);

if(newTitle!==null){

title.innerText=newTitle;
}

if(newDesc!==null){

desc.innerText=newDesc;
}

}


function deleteTask(button){

let task=button.parentElement.parentElement;

task.remove();

}