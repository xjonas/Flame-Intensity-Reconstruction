# Abel Inversion of Flame Intensity – C++ Implementation

## Theoretical Background

In combustion diagnostics, optical methods are essential for analyzing flame characteristics. One common technique captures the self-emission of radicals within the flame front. However, such measurements often yield only a **cross-sectional intensity distribution**, losing spatial resolution due to line-of-sight integration.

<p align="center">
<img width="700" alt="Screenshot 2025-03-05 at 22 02 51" src="https://github.com/user-attachments/assets/47aa8d5a-6786-4734-9607-b334b30c913c" />
<img width="700" alt="Screenshot 2025-03-05 at 22 04 11" src="https://github.com/user-attachments/assets/68ec321f-b4dc-4352-96e7-5de979c70172" />
</p>

For **rotationally symmetric flames**, the actual **radial intensity distribution** \( f(r) \) can be reconstructed from the measured line-of-sight projection \( I(y) \) through the **Abel inversion**, based on the following integral relationship:

### Abel Integral Equation:

  <img width="350" alt="Screenshot 2025-03-05 at 22 03 34" src="https://github.com/user-attachments/assets/acbb9fd6-8e8d-4ee1-9acd-e43867de61f0" />

### Inverted Form (Abel Inversion):

<img width="350" alt="Screenshot 2025-03-05 at 22 03 53" src="https://github.com/user-attachments/assets/acb4d47d-fde8-4ea1-ad02-0bfa88b2d0cb" />

Where:
- I(y): Measured cross-sectional intensity at position \( y \).
- f(r): Radial intensity at radius \( r \).
- R: Maximum radius of the flame.

The inversion is numerically challenging due to the singularity at y = r and requires:
- **Smoothing** (to minimize noise in I(y)).
- **Polynomial fitting** (for differentiation).
- **Symmetry correction** (by mirroring and averaging the flame image).
- **Integration** (to reconstruct f(r)).

The goal of this program is to accurately calculate f(r) from the raw intensity profiles of experimental flame images.

---

## Code Structure

The program is modularized into separate headers and functions, as shown below:

```
├── main.cpp                 # Main program control
├── Create_Delete_Matrix.h   # Dynamic memory management for matrices
├── GetData.h                # Import of raw flame intensity data
├── Spiegeln.h               # Symmetry correction (mirroring)
├── Mittelung.h              # Averaging and smoothing routines
├── Glaettung.h              # Noise reduction using moving averages
├── PolynomFit.h             # Polynomial fitting for intensity data
├── Differentiation.h        # Numerical differentiation (central differences)
├── Integration.h            # Abel inversion via numerical integration
├── IntegrationVollständig.h # Full matrix integration across all heights (z-levels)
├── FunktionsWert.h          # Evaluation of polynomial functions
├── Variablen.h              # Global parameters and constants
├── WriteData.h              # Output functions (results as .txt)
├── raw/                     # Input directory for raw data files
└── results/                 # Output directory for processed results
```

### Key Features
- Reads raw flame intensity data (e.g., from Tecplot `.txt` files).
- Applies Abel inversion to compute radial intensity distributions.
- Supports processing full flame images (512x512 pixels).
- Outputs reconstructed data as `.txt` for plotting in **Excel**, **Gnuplot**, or other tools.
- Modular structure to allow independent testing of components.

---

## How to Use the Code

### 1️⃣ Requirements
- **C++ compiler** (e.g., g++, clang++).
- C++11 or higher standard.
- Tools like **Gnuplot**, **Excel**, or **Python** for plotting.

### 2️⃣ Compilation
Use any standard C++ compiler. Example with g++:
```bash
g++ -std=c++11 main.cpp -o abel_inversion
```

### 3️⃣ Running the Program
Run the compiled executable:
```bash
./abel_inversion
```

### 4️⃣ Input Data
- Place raw flame intensity files in the `/raw/` directory.
- The program processes each z-level (row) of the matrix and applies the Abel inversion.
- Ensure proper symmetry correction using `Spiegeln.h` before inversion.

### 5️⃣ Output
- Processed radial intensity profiles are saved in `/results/` as text files.
- These files can be directly imported into plotting tools.

### 6️⃣ Visualization
Example visualization workflows:
- **Excel**: Load `.csv` or `.txt` outputs and plot line graphs.
- **Gnuplot**: Plot profiles with simple commands like:
  ```
  plot 'results/profile.txt' using 1:2 with lines
  ```

---

## Notes
- Parameters (like polynomial degree, smoothing intervals) can be easily adjusted in `Variablen.h`.
- Works best with **rotationally symmetric** flames and clean intensity profiles.

---
