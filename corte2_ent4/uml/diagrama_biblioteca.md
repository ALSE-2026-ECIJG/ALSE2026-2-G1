# Diagrama UML — Sistema de Gestión de Biblioteca

```mermaid
classDiagram
    direction LR

    class Libro {
        -string titulo
        -string autor
        -string isbn
        -bool disponible
        +Libro()
        +Libro(titulo, autor, isbn, disponible)
        +getTitulo() string
        +getAutor() string
        +getIsbn() string
        +isDisponible() bool
        +setDisponible(bool) void
        +mostrarInfo() void
    }

    class Usuario {
        <<abstract>>
        #string nombre
        #int id
        #int limitePrestamos
        #vector~string~ prestamosActivos
        +Usuario(nombre, id, limitePrestamos)
        +~Usuario()
        +getNombre() string
        +getId() int
        +getLimitePrestamos() int
        +getPrestamosActivos() int
        +puedePrestar() bool
        +agregarPrestamo(isbn) void
        +devolverPrestamo(isbn) void
        +getRol()* string
        +mostrarInfo() void
    }

    class Estudiante {
        +Estudiante(nombre, id)
        +getRol() string
    }

    class Profesor {
        +Profesor(nombre, id)
        +getRol() string
    }

    class Biblioteca {
        -vector~Libro~ libros
        +agregarLibro(Libro) bool
        +eliminarLibro(isbn) bool
        +buscarPorTitulo(titulo) vector~Libro~
        +buscarPorAutor(autor) vector~Libro~
        +librosDisponibles() vector~Libro~
        +prestarLibro(isbn, Usuario) bool
        +devolverLibro(isbn, Usuario) bool
        +mostrarCatalogo() void
        +totalLibros() size_t
    }

    Usuario <|-- Estudiante : herencia
    Usuario <|-- Profesor   : herencia

    Biblioteca "1" *-- "0..*" Libro : composicion
    Biblioteca ..> Usuario : dependencia
```

## Notas de diseño

### Relaciones

- **Generalización (herencia):** `Estudiante` y `Profesor` heredan de `Usuario`.
  La clase `Usuario` es abstracta (tiene `getRol()` virtual puro).

- **Composición:** `Biblioteca` ◆→ `Libro`. Los libros viven dentro de la
  biblioteca como `std::vector<Libro>` (por valor). Si la biblioteca se
  destruye, los libros también. Multiplicidad: `1` a `0..*`.

- **Dependencia:** `Biblioteca` ⇢ `Usuario`. Los métodos
  `prestarLibro(isbn, Usuario&)` y `devolverLibro(isbn, Usuario&)` reciben
  un `Usuario` por referencia, pero `Biblioteca` no lo almacena.
  Es una dependencia de uso, no de composición.

### Multiplicidades

- `Biblioteca "1" *-- "0..*" Libro` → una biblioteca contiene cero o más libros.
- Un `Libro` pertenece a exactamente una biblioteca (por diseño actual).

### Atributos y métodos

- `-` privado
- `#` protegido
- `+` público
- `*` método abstracto
