# 🎲 Enfrendados

**Enfrendados** es un juego de dados desarrollado en C++ como parte del Trabajo Práctico Integrador de la materia **Programación I** (Técnico Universitario en Programación - 2025, 1C).

Combina azar y matemáticas para enfrentar a dos jugadores en una partida de tres rondas. El objetivo: sumar la mayor cantidad de puntos posibles o quedarse sin dados para obtener una victoria automática.

---

## 📌 Requisitos del proyecto

- Lenguaje: **C++**
- Tipo de aplicación: **Consola**
- Participantes: mínimo **2**, máximo **4**
- Uso de:
  - Vectores
  - Funciones
  - Generación aleatoria con `rand()` y `srand()`
- No se permite:
  - Uso de variables globales
  - Instrucción `goto`

---

## 🕹️ Cómo se juega

Cada jugador comienza con 6 dados de **6 caras** (dados stock). Además, se lanzan 2 dados de **12 caras** al comienzo de cada turno para determinar el **número objetivo**.

### Objetivo

- Seleccionar dados de tu stock cuya suma sea igual al número objetivo.
- Si lo lográs:
  - Sumás puntos: `suma seleccionada × cantidad de dados usados`
  - Transferís esos dados al contrincante.
- Si fallás:
  - Podés recibir 1 dado de tu oponente (si tiene más de uno).

### Condición de victoria

- Si un jugador realiza una **tirada exitosa** y se queda sin dados → **gana automáticamente** y suma **10.000 puntos**.
- Si se completan las 3 rondas, gana quien haya acumulado más puntos.
- En caso de empate, el juego termina igualado.

---

## 📋 Menú principal


### Opciones:

- **JUGAR**: Inicia una nueva partida, pidiendo los nombres de los jugadores.
- **ESTADÍSTICAS**: Muestra el jugador con mayor puntaje histórico desde que se abrió el programa.
- **CRÉDITOS**: Lista los integrantes del equipo y su legajo.
- **SALIR**: Sale del juego con confirmación del usuario.

---

## 🧠 Vocabulario clave

| Término             | Descripción |
|---------------------|-------------|
| **Dados stock**     | Dados de 6 caras que tiene cada jugador. |
| **Dados objetivo**  | Dos dados de 12 caras que determinan la suma objetivo. |
| **Número objetivo** | Suma de los dados objetivo. |
| **Dados elegidos**  | Dados del stock seleccionados para intentar igualar el número objetivo. |
| **Suma seleccionada** | Resultado de sumar los dados elegidos. |
| **Tirada exitosa**  | Cuando la suma seleccionada = número objetivo. |
| **Puntaje de ronda** | `suma seleccionada × cantidad de dados elegidos`. |
| **Transferencia de dados** | En tirada exitosa, los dados usados pasan al oponente. |
| **Victoria automática** | Si un jugador se queda sin dados tras una tirada exitosa, gana y suma 10.000 puntos. |

---

## 📷 Simulación de partida

Ejemplo resumen de una ronda:

- Angel lanza dados objetivo: 7 + 5 → número objetivo: 12  
- Stock de Angel: [3, 4, 2, 6, 1, 5]  
- Combinación seleccionada: 3 + 4 + 5 = 12 ✅  
- Dados elegidos: 3  
- Puntos: 12 × 3 = 36  
- Angel transfiere 3 dados a María

Y así sucesivamente durante 3 rondas.

---

## 👨‍💻 Créditos

- Juego inventado por: **Angel Simón**
- Inspirado levemente en el juego **Mafia**
- Íconos: [Freepik](https://www.freepik.com)
- Logo: [Logo Maker](https://logomaker.com)
- Desarrollado por el equipo:

  - **Tomas Juarez**
  - **Delfina Sarkis**
  - **Juan Alvarez Ruiz**

---

## 🚧 Consideraciones finales

- Las tiradas de dados deben ser aleatorias.
- No se permite deshacer la selección de dados.
- Si el jugador no puede igualar el número objetivo, puede ingresar `0` para terminar la ronda como no exitosa.
- Las estadísticas se reinician al cerrar el programa.

---

¡Que gane el mejor! 🎲
