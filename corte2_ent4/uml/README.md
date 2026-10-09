# Ejercicio 4 — Diagrama UML

Diagrama UML del **Sistema de Gestión de Biblioteca** (Ejercicio 1),
elaborado con [Mermaid](https://mermaid.js.org/).

## Archivos

- `diagrama_biblioteca.md` — código Mermaid del diagrama de clases.

## Cómo visualizarlo

### Opción 1 — GitHub (recomendado)

GitHub renderiza Mermaid automáticamente. Abre `diagrama_biblioteca.md`
en el navegador y verás el diagrama dibujado.

### Opción 2 — VSCode

Instala la extensión **"Markdown Preview Mermaid Support"** de Matt Bierner.
Luego abre `diagrama_biblioteca.md` y presiona `Ctrl+Shift+V`.

### Opción 3 — Exportar a imagen (para el PDF del informe)

Con la CLI de Mermaid (`mmdc`):

```bash
npm install -g @mermaid-js/mermaid-cli
mmdc -i diagrama_biblioteca.md -o diagrama_biblioteca.png
