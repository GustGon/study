" execucao do gerenciador de plugins
execute pathogen#infect()

" Enumera as linhas
set number

" Colore o editor
syntax on

" [BUG FIX] evita de perder a cor da syntax em arquivos grandes
set redrawtime=10000

" tamanho da indentacao
set tabstop=4

" Auto indenta
set autoindent

" Tab vira espaços
set expandtab

" Apaga uma identacao inteira
set softtabstop=4

" esquema de cotes
colorscheme gruvbox

" abilita modo escuro do gruvbox
set bg=dark

" identifica o tipo do arquivo e identa
filetype plugin indent on

" deixa corrente de indentacao com tamanha TAB
set shiftwidth=4

" distancia relativa da linha
set relativenumber

" busca incremental
set incsearch

" destaque nos resultados
set hlsearch

" auto complete
let g:snipMate = { 'snippet_version' : 1 }

" fold functions
" zf#j creates a fold from the cursor down # lines.
" zf/ string creates a fold from the cursor to string .
" zj moves the cursor to the next fold.
" zk moves the cursor to the previous fold.
" za toggle a fold at the cursor.
" zo opens a fold at the cursor.
" zO opens all folds at the cursor.
" zc closes a fold under cursor. 
" zm increases the foldlevel by one.
" zM closes all open folds.
" zr decreases the foldlevel by one.
" zR decreases the foldlevel to zero -- all folds will be open.
" zd deletes the fold at the cursor.
" zE deletes all folds.
" [z move to start of open fold.
" ]z move to end of open fold.
set foldmethod=indent
set foldlevel=1

" copy to clip board
" V"+y
set clipboard=unnamedplus
