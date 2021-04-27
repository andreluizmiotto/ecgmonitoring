# ecgmonitoring

Undergraduate final project presented to the Computer Engineering Course at the Universidade do Oeste de Santa Catarina.

This repository consists of two projects, composing an embedded system:
  * FirmwareECGMonitor.X, for the PIC18F4550, developed in C with MpLab X;
  * Supervisory, for communication with the hardware, developed in C++ with Embarcadero C++ Builder 10.

# Final paper abstract
The present work shows a computational system, integrating hardware and software, capable
of performing the acquisition, conditioning, wireless transmission and graphic reproduction of
electrocardiographic signals, in real time, from the positioning of electrodes on the skin surface.
The hardware comprises the steps of acquisition, amplification, analog filtering and wireless
signal transmission, using an AD8232 front-end, a PIC18F4550 microcontroller and an HC-06
bluetooth module. The software comprises the stages of digital processing and filtering, and
graphic reproduction of the sportsman’s electrocardiographic tracing. Through the software it
is also possible to upload and graphically reproduce previously packaged samples, stored in
standard ECG files. Although the hardware prototype needs numerous improvements to work in
adverse conditions, the results obtained are encouraging, enabling the proposed methodology.

# Final paper (in portuguese)
[TCC II - André Luiz Miotto.pdf](https://github.com/andreluizmiotto/ecgmonitoring/files/6386429/TCC.II.-.Andre.Luiz.Miotto.pdf)

# Supervisory main screen
![Soft_Supervisorio](https://user-images.githubusercontent.com/43590504/116285130-37d1da00-a764-11eb-9375-17aad5b336d4.png)

# Acquisition of real cardiac biopotentials at 400 Hz
![ECG_400HzFiltrado](https://user-images.githubusercontent.com/43590504/116285614-ab73e700-a764-11eb-8cf4-978bac82169d.png)
