# Robot Omnidirecțional cu Control Personalizat prin Bluetooth

## Descriere generală
Acest proiect implementează un **robot omnidirecțional cu roți mecanum**, controlat de la distanță printr-un **controller personalizat** bazat pe joystickuri și comunicație **wireless Bluetooth**.  

Robotul oferă **mobilitate completă pe orizontală**, permițând deplasare înainte, înapoi, lateral și rotație pe loc. Controller-ul transmite comenzile către robot prin module HC-05, permițând **control intuitiv și bidirecțional**, inclusiv posibilitatea de feedback către operator.  

## Scopul proiectului
- Crearea unei soluții de control fără fir pentru un robot omnidirecțional.  
- Implementarea comunicației bidirecționale între controller și robot.  
- Asigurarea **preciziei și stabilității** mișcării robotului.  

## Soluția propusă
- Robotul utilizează **roți mecanum** pentru mișcare omnidirecțională.  
- Controlul este realizat prin **două joystickuri**, care permit control separat al direcției și rotației.  
- **Driverele de motoare** și Arduino gestionează viteza și direcția motoarelor DC, iar **HC-05** asigură comunicarea wireless între controller și robot.  

Această arhitectură permite **interacțiune intuitivă**, fără cabluri, demonstrând funcționalitatea robotului într-un mod clar.
