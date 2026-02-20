# NexusC - Bot de Trading en C puro

**Proyecto en desarrollo activo** — Fase: Sentando las bases

---

## Descripción

NexusC es un **bot de trading backtesting** escrito **100% en C** (sin dependencias externas).

Funciona leyendo un archivo CSV de **granularidad 1 minuto** (OHLC + volumen) y aplica una estrategia **CRT (Cascada de Reglas de Trading)** que opera en modo cascada:

- Analiza **3 timeframes simultáneamente** (HTF → madre + 2 LTF).
- Solo entra en mercado cuando **las 3 reglas se cumplen al mismo tiempo**.
- Genera al final una tabla completa de estadísticas: Winrate, PnL neto, Profit Factor, Drawdown, etc.

---

## Estado actual del proyecto (TO-DO)

### ✅ Fase actual: Arquitectura base

- [ ] `src/csv_reader.c`  
  → Lectura completa del CSV  
  → Parsing por token configurable  
  → Separación automática de headers y datos  
  → Asignación dinámica a columnas  
  → Creación de índice (especialmente para columna datetime)

- [ ] `src/datetime.c`  
  → Todas las funciones de manejo y conversión de fechas/horas  
  → Soporte para múltiples formatos de timestamp

- [ ] `src/NexusC.c`  
  → Motor principal de la lógica CRT  
  → Gestión de cascada HTF → LTF  
  → Evaluación de reglas en múltiples timeframes

- [ ] `src/main.c`  
  → Punto de entrada del programa  
  → Carga del CSV  
  → Preparación de estructuras de datos  
  → Llamada a `NexusC()` con:  
    - Ruta del CSV  
    - Saldo inicial  
    - Timeframe madre (HTF)  
    - Parámetros de la estrategia  
  → Generación automática de tabla estadística final

---

## Estructura del proyecto

```bash
NexusC/
├── src/
│   ├── main.c
│   ├── csv_reader.c
│   ├── datetime.c
│   └── NexusC.c
├── include/               # (headers .h cuando se creen)
├── data/                  # ← aquí irán los CSVs de prueba
├── results/               # ← tablas de resultados y logs
├── Makefile
├── README.md
└── LICENSE
