# Tattoo Studio Data Analysis System (C)

## Project Description

This project is a C-based system designed to process and analyze customer service data from a tattoo studio.

Data is loaded from a CSV file and processed using structured programming concepts. The system generates statistical analysis, probability distribution, and exports summarized data for external visualization tools such as Excel.

---

## Objectives

- Read structured data from a CSV file
- Store data using C structs
- Perform statistical analysis
- Compute empirical probability distributions
- Generate insights about business performance
- Export processed data for external analysis (Excel)

---

## Features

### ✔ Data Processing
- CSV file reading
- Structured data storage using `struct`

### ✔ Statistical Analysis
- Minimum value
- Maximum value
- Average ticket value

### ✔ Probability Analysis
- Value distribution by ranges:
  - Low (≤ 300)
  - Medium (≤ 600)
  - High (> 600)

### ✔ Business Insights
- Revenue patterns
- Customer behavior interpretation
- Simple data-driven insights

### ✔ Data Export
- Generates CSV file (`analysis.csv`)
- Compatible with Excel for chart visualization

---

## Input Format (CSV)
```csv
cliente,data,servico,valor
Diego,03/01/2026,Tatuagem,800
Ana,04/01/2026,Fineline,500
João,05/01/2026,Old School,300
```
---

## Project Structure
```
tatuagem-c-system/
├── src/
│   ├── main.c
│   ├── model.h
│   ├── reader.c
│   ├── stats.c
│   └── report.c
│
├── data/
│   └── file.csv
│
├── .gitignore
└── README.md
```
---

## How to Build and Run

### Compile:
```bash
gcc src/main.c src/reader.c src/stats.c src/report.c -o app
```

### Run:
```
./app
```

### Output

The system provides:

* Console report with service records
* Statistical summary
* Probability distribution
* Business insights
* Exported file: analysis.csv

### Excel Visualization

The exported analysis.csv file can be opened in Excel to generate charts and visual analysis of revenue distribution.

### Concepts Applied
Modular programming in C
File handling (fopen, fgets)
Structs and data modeling
Descriptive statistics
Empirical probability
Data export for external visualization

### Author

Academic project developed for learning purposes, combining C programming and introductory data analysis concepts.
