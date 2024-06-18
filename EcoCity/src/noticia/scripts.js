const todoList = document.getElementById('noticia-ul');
const modal = document.querySelector('dialog');
const openDialog = document.getElementById('add-dialog');
const form = document.querySelector('form');

openDialog.addEventListener('click', () => {
  modal.showModal();
});

form.addEventListener('submit', addItemUL);

function addItemUL(event) {
  event.preventDefault(); // previne o comportamento padrão do formulário
  const tipo = document.getElementById('tipo').value
  const title = document.getElementById('title').value;
  const description = document.getElementById('description').value;
  const image = document.getElementById('add-img').files[0];

  const listItem = document.createElement('li');
  listItem.classList.add('noticia-li')
  listItem.innerHTML = `
    <h1>${tipo}</H1>
    <img src="${URL.createObjectURL(image)}" alt="${title}">
    <div class="conteudo">
    <h1>${title}</h1>
    <p>${description}</p>
    </div>
    <div class="icons">
      <svg xmlns="http://www.w3.org/2000/svg" width="30" height="30" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-heart"><path d="M19 14c1.49-1.46 3-3.21 3-5.5A5.5 5.5 0 0 0 16.5 3c-1.76 0-3 .5-4.5 2-1.5-1.5-2.74-2-4.5-2A5.5 5.5 0 0 0 2 8.5c0 2.3 1.5 4.05 3 5.5l7 7Z"/></svg>
      <svg xmlns="http://www.w3.org/2000/svg" width="30" height="30" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-download"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"/><polyline points="7 10 12 15 17 10"/><line x1="12" x2="12" y1="15" y2="3"/></svg>
    </div>
                    <button class="saibaMais">Saiba mais</button>

  `;
  todoList.appendChild(listItem);

  // limpa os campos do formulário
  document.getElementById('title').value = '';
  document.getElementById('description').value = '';
  document.getElementById('add-img').value = '';

  // fecha o dialog
  modal.close();
}