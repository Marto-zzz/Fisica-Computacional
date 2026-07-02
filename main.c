#include <stdio.h>
#include <math.h>
#include <time.h>   // <-- necesario para medir tiempo

#define PI 3.14159265358979323846
#define N 300

int main() {

    // Frecuencia de muestreo
    double fs = 100.0;

    // Arreglos para tiempo y señal
    double t[N];
    double x[N];

    // Arreglos para la DFT
    double X_real[N];
    double X_imag[N];
    double magnitud[N];
    double frecuencia[N];

    // ============================
    // Generación de la señal
    // ============================

    for (int n = 0; n < N; n++) {

        t[n] = n / fs;

        x[n] = sin(2 * PI * 4 * t[n])
             + 0.8 * sin(2 * PI * 7 * t[n]);
    }

    // ============================
    // INICIO MEDICIÓN DE TIEMPO
    // ============================

    clock_t inicio = clock();

    // ============================
    // Transformada Discreta de Fourier
    // ============================

    for (int k = 0; k < N; k++) {

        X_real[k] = 0.0;
        X_imag[k] = 0.0;

        for (int n = 0; n < N; n++) {

            double angulo = 2 * PI * k * n / N;

            X_real[k] += x[n] * cos(angulo);
            X_imag[k] -= x[n] * sin(angulo);
        }

        magnitud[k] = sqrt(X_real[k]*X_real[k] +
                           X_imag[k]*X_imag[k]);

        frecuencia[k] = k * fs / N;
    }

    // ============================
    // FIN MEDICIÓN DE TIEMPO
    // ============================

    clock_t fin = clock();

    double tiempo_segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion DFT: %f segundos\n", tiempo_segundos);

    // ============================
    // Guardar señal
    // ============================

    FILE *senal = fopen("senal.csv", "w");
    fprintf(senal, "Tiempo,Amplitud\n");

    for (int i = 0; i < N; i++) {
        fprintf(senal, "%lf,%lf\n", t[i], x[i]);
    }

    fclose(senal);

    // ============================
    // Guardar espectro
    // ============================

    FILE *espectro = fopen("espectro.csv", "w");
    fprintf(espectro, "Frecuencia,Magnitud\n");

    for (int i = 0; i < N/2; i++) {
        fprintf(espectro, "%lf,%lf\n",
                frecuencia[i],
                magnitud[i]);
    }

    fclose(espectro);

    printf("Proceso finalizado correctamente.\n");

    return 0;
}
