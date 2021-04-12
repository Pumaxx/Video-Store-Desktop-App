# Video Store Desktop App

# Opis programu

Jest to program symulujący wypożyczalnie filmów obsługujący 3 główne okna (logowanie, panel administratora, panel użytkownika)

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391926-65315c00-9b98-11eb-83e4-d473d4238993.png" />
</p>

**Okno logowania:**
- po podaniu loginu i hasła (admin, admin1) logujemy się do panelu administratora
- po podaniu loginu i hasła jednego z użytkowników (znajdujące się w pliku logowanie.txt, (np. jan, kowalski) logujemy się do panelu użytkownika
- w przypadku podania loginu i hasła nie znajdujących się w pliku logowanie.txt wyskakuje nam komunikat błędu


**Okno administratora:**
- składa się z 3 głównych zakładek (Filmy, Usuń użytkownika, Dodaj użytkownika)

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391927-65315c00-9b98-11eb-8a55-db819121e091.png" />
</p>

- **zakładka filmy:**
  - w głównej części zakładki wyświetlane są dostępne filmy i ich ceny za dzień pobierane z pliku wypozycz.txt
  - administrator posiada możliwość dodania nowego filmu, usunięcia jednego z nich lub zmiany jego ceny, wprowadzając w tym zmianę w pliku wypozycz.txt
  - usunięcie i zmiana ceny możliwa jest jedynie po wpisaniu poprawnego tytułu filmu z pliku wypozycz.txt

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114392789-8fcfe480-9b99-11eb-9f56-e153e3d4de90.png" />
</p>

- **zakładka usuń użytkownika:**
    - po wpisaniu loginu i hasła jednego z istniejących użytkowników, dane te usuwane są z pliku logowanie.txt
    - usuwany jest też plik użytkownika zawierający wypożyczone przez niego filmy, znajdujący się w folderze Uzytkownicy

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391932-65c9f280-9b98-11eb-876f-a9d1ffa5dd4b.png" />
</p>

- **zakładka dodaj użytkownika:**
    - po wpisaniu loginu i hasła dodawane są one do pliku logowanie.txt

- ostania częścią panelu administratora jest przycisk Wyloguj cofający nas do okna logowania 


**Okno użytkownika:**
- składa się z 3 głównych zakładek (Moje filmy, Wypożycz film,  Zmień hasło)

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391933-66628900-9b98-11eb-9fa4-9326e2068400.png" />
</p>

**zakładka moje filmy:**
    - wyświetlane są filmy, które są obecnie wypożyczone przez użytkownika, pobrane z pliku tekstowego o nazwie jego loginu, znajdujące się w folderze Uzytkownicy
    - użytkownik posiada możliwość zwrócenia filmu po wpisaniu poprawnego tytułu, który zostanie usunięty z pliku testowego

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391925-6498c580-9b98-11eb-9858-46bb125349f1.png" />
</p>

**zakładka wypożycz film:**
    - wyświetlane są filmy możliwe do wypożyczenia pobrane z pliku wypozycz.txt, co skutkuje dodaniem go do pliku tekstowego o nazwie loginu tego użytkownika

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391935-66628900-9b98-11eb-91f0-110a4e7c12f7.png" />
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/72915573/114391936-66628900-9b98-11eb-87e7-ae1e5df7cd81.png" />
</p>

**zakładka zmień hasło:**
    - po wpisaniu tego samego hasła i loginu użytego podczas logowania wyświetla się okno podania nowego hasła i powtórzenia go 
    - po wpisaniu 2 takich samych haseł, hasło tego użytkownika zostaje zmienione w pliku logowanie.txt

- ostatnią częścią panelu użytkownika jest przycisk Wyloguj cofający nas do okna logowania 

