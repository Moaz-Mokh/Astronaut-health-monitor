# Astronaut-health-monitor
Simple code that monitors the astronaut health throughout the mission saves the old data using CRV and reads the new data and compares it to the old data and graphs it using OCTAVE here are the details:

A command-line tool that lets an astronaut log daily vitals, see whether each one is LOW / NORMAL / HIGH,
get one weighted **risk score out of 21**, and follow their health trend across the mission.
Data is stored in a CSV file and plotted with GNU Octave.

## The problem
Long-duration missions put crews far from Earth-based medical care. Small changes in vitals or sleep are easy
to miss from one day to the next, and eight raw readings a day are hard to judge without a clear signal.
This project turns those readings into a status per vital, a single risk score, and a trend over the mission,
using a tool that runs offline on any laptop.

## Features
- **Daily vitals input:** systolic/diastolic blood pressure, respiratory rate, temperature, heart rate, blood sugar, sleep hours and SpO2.
- **Instant status:** every vital is flagged LOW / NORMAL / HIGH (sleep: INSUFFICIENT / BALANCED / OVERSLEEPING).
- **Risk score:** a weighted score out of **21**, also shown as a percentage.
- **Mission log:** each day is appended to `src/astronaut-data.csv`.
- **Trend analysis:** mission averages, and how today differs from them in value and in percent.
- **Plots:** Octave charts for every vital, blood pressure and the daily risk trend.

## How it works

```
Input  ->  Classify  ->  Risk engine  ->  CSV store  ->  Analyze & plot
(8 readings) (LOW/NORMAL/HIGH) (score out of 21) (one row per day) (averages, differences, Octave)
```

1. The astronaut enters the date and the daily readings.
2. Each vital is classified against its normal range.
3. The risk engine gives every vital group points by severity:

   | Severity | Points |
   
   | Normal | 0 |
   | Mild concern | 0.5 |
   | Moderate concern | 1 |
   | Severe concern | 3 |

   There are 7 vital groups (blood pressure, heart rate, respiratory rate, temperature, blood sugar, sleep, SpO2),
   so the maximum is 7 x 3 = **21 points**. Blood pressure uses the worse of the systolic and diastolic scores.
   `Risk % = points / 21 x 100`.
5. The day is appended to the CSV file.
6. The CSV is re-read, so the mission averages always include today, and today's values are compared with them.
7. `octave/plots.m` plots the whole history.

### Risk bands
| Vital | Normal (0) | Mild (0.5) | Moderate (1) | Severe (3) |

| Systolic BP (mmHg) | 90-120 | 85-90, 120-130 | 80-85, 130-140 | otherwise |
| Diastolic BP (mmHg) | 60-80 | 55-60, 80-85 | 50-55, 85-90 | otherwise |
| Heart rate (bpm) | 60-100 | 50-60, 100-110 | 40-50, 110-130 | otherwise |
| Respiratory rate (breaths/min) | 12-20 | 10-12, 20-24 | 8-10, 24-30 | otherwise |
| Temperature (C) | 36.1-37.2 | 35.5-36.1, 37.2-37.8 | 35.0-35.5, 37.8-38.5 | otherwise |
| Blood sugar (mg/dL) | 70-100 | 60-70, 100-110 | 50-60, 110-125 | otherwise |
| Sleep (hours) | 7-9 | 6-7, 9-10 | 5-6, 10-11 | otherwise |
| SpO2 (%) | 95-100 | 92-95 | 88-92 | otherwise |

## Project structure
```
src/main.cpp            C++ program: input, classification, risk engine, CSV, averages
src/astronaut-data.csv  Sample mission data (simulated, not real astronaut data)
octave/plots.m          Plots every column of the CSV and saves PNGs to docs/plots/
docs/                   Documentation
README.md
```

## Build and run
Requirements: a C++17 compiler (g++, clang or MSVC) and GNU Octave (for the plots).

```bash
 1. build (from the project root)
g++ -std=c++17 -o main src/main.cpp

 2. log today's vitals (run from src/ so the CSV is found)
cd src
../main            # on Windows: ..\main.exe

 3. plot (from the project root)
cd ../octave
octave plots.m
```

Input order: date, systolic BP, diastolic BP, respiratory rate, temperature, heart rate, blood sugar, sleep hours, SpO2.

### Example run
```
Welcome Astronaut! Enter the date (D/M/YYYY): 16/11/2026
...
Your risk score is 0/21
Your risk percentage is 0%

===== MISSION AVERAGES (12 days) =====
Average heart rate        = 95.0833
...
===== TODAY vs AVERAGE =====
Heart rate:       -23.0833  (-24.277%)
```

## What's next
  Desktop GUI: a live dashboard with colour-coded status and trend alerts when risk keeps rising.
  Deeper vitals: for example bone density loss, a known risk of long spaceflight, plus muscle mass and other long-term markers.
  CAD-designed measurement tools: CAD models of compact, 3D-printable sensors, holders and cuffs for taking these measurements in microgravity, feeding readings straight into the monitor.
  Personal baselines: per-astronaut baselines and mission-specific limits drawn from NASA human-research data instead of general adult reference ranges.

 Limitations
- Thresholds are general adult reference ranges, not mission-specific medical limits.
- Not a medical device. The sample data is simulated.

