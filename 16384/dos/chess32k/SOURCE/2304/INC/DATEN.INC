;<<<---Daten--->>>
.DATA
Copyright db 'Chess32k by SpaceCommander / ByTeGeiZ$'
Configdatei db 'Chess32k.cfg',0
Men�0 db '���������������������������������������Ļ$'
Men�1 db '�                                       �$'
Men�2 db '���������������������������������������Ĵ$'
Men�3 db '�               1  Spieler              �$'
Men�4 db '�               2  Spieler              �$'
Men�5 db '�                Optionen               �$'
Men�6 db '�                 Regeln                �$'
Men�7 db '�                  Info                 �$'
Men�8 db '�                  Ende                 �$'
Men�9 db '���������������������������������������ļ$'
Schachbrett1 db '�������������������������������ͻ$'
Schachbrett2 db '�   �   �   �   �   �   �   �   �$'
Schachbrett3 db '�������������������������������Ĺ$'
Schachbrett4 db '�������������������������������ͼ$'
Spielername1 db '�����������������������������Ļ$'
Spielername2 db '� Bitte Spielernamen eingeben �$'
Spielername3 db '�����������������������������Ĵ$'
Spielername4 db '�  Weiss  :                   �$'
Spielername5 db '� Schwarz :                   �$'
Spielername6 db '�����������������������������ļ$'
Spielername7 db '� Spieler :                   �$'
Optionen0 db '�������������������������������������Ļ$'
Optionen1 db '�               Optionen              �$'
Optionen2 db '�������������������������������������Ĵ$'
Optionen3 db '�         Koordinaten anzeigen        �$'
Optionen4 db '�            Namen anzeigen           �$'
Optionen5 db '�          Schachuhr anzeigen         �$'
Optionen6 db '�         Zugnotation anzeigen        �$'
Optionen7 db '�     Geschlagene Figuren anzeigen    �$'
Optionen8 db '�         Bemerkungen anzeigen        �$'
Optionen9 db '�    Optionen automatisch speichern   �$'
OptionenA db '�               Hauptmen�             �$'
OptionenB db '�������������������������������������ļ$'
Info0 db '���������������������������������Ļ$'
Info1 db '�              Info               �$'
Info2 db '���������������������������������Ĵ$'
Info3 db '�   Code + Idee: SpaceCommander   �$'
Info5 db '�          Version: 0.85P         �$'
Info6 db '� Source: 150 kB Asm, 7500 Zeilen �$'
Info4 db '�    Betatester: MK2K , Kilroy    �$'
Info7 db '� ByTeGeiZ sucht neue Mitglieder! �$'
Info8 db '� Homepage: http://go.to/ByTeGeiZ �$'
Info9 db '���������������������������������ļ$'
Geschlagene_Figuren_Fenster0 db '���������������������Ļ$'
Geschlagene_Figuren_Fenster1 db '� Geschlagene Figuren �$'
Geschlagene_Figuren_Fenster2 db '���������������������Ĵ$'
Geschlagene_Figuren_Fenster3 db '�                     �$'
Geschlagene_Figuren_Fenster4 db '�                     �$'
Geschlagene_Figuren_Fenster5 db '���������������������ļ$'
Zugnotation_Fenster0 db '������������������Ļ$'
Zugnotation_Fenster1 db '� Zugnotation      �$'
Zugnotation_Fenster2 db '������������������Ĵ$'
Zugnotation_Fenster3 db '�                  �$'
Zugnotation_Fenster4 db '������������������ļ$'
Schachuhr0 db '����������Ļ$'
Schachuhr1 db '� 00:00:00 �$'
Schachuhr2 db '����������ļ$'
Seitenwahl0 db '���������������Ļ$'
Seitenwahl1 db '� Welche Farbe? �$'
Seitenwahl2 db '���������������Ĵ$'
Seitenwahl3 db '�    Zufall     �$'
Seitenwahl4 db '�     Wei�      �$'
Seitenwahl5 db '�    Schwarz    �$'
Seitenwahl6 db '���������������ļ$'
Kommentar_Fenster0 db '���������������Ļ$'
Kommentar_Fenster1 db '�               �$'
Kommentar_Fenster2 db '�               �$'
Kommentar_Fenster3 db '�               �$'
Kommentar_Fenster4 db '�               �$'
Kommentar_Fenster5 db '���������������ļ$'
Spielende_Fenster0 db '������������������Ļ$'
Spielende_Fenster1 db '� Du hast          �$'
Spielende_Fenster2 db '������������������ļ$'
Spielende_gewonnen db 'gewonnen$'
Spielende_verloren db 'verloren$'
Cursor_sicherung db 10
Spieler1 db 17 dup (20h),'$'
Spieler2 db 17 dup (20h),'$'
Spieler3 db 17 dup (20h),'$'
Notation_String db 16 dup (20h),'$'
Computer_Name db 'Chess32k         $'
Spieler1_Namensl�nge dw 0
Spieler2_Namensl�nge dw 0
Spieler3_Namensl�nge dw 0
Letzte_Sekunde db 0
Einspielermodus db 0
Farbe_ausgew�hlt db 0
Bemerkung_leer db '                   $'
Bemerkung1 db 'Patt!$'
Bemerkung2 db 'Du gibst auf?$'
Bemerkung3 db 'Hast du Angst?$'
Bemerkung4 db 'Hosen voll?$'
Bemerkung5 db 'Keine Lust mehr?$'
Bemerkung6 db 'Und Gluck weg isser$'
Bemerkung7 db 'Einer weniger$'
Bemerkung8 db 'Die anderen folgen$'
Bemerkung9 db 'Der N�chste bitte$'
Bemerkung10 db 'Schl�fst du?$'
Bemerkung11 db 'Der war zuviel hier$'
Bemerkung12 db 'Schade eigentlich$'
Bemerkung13 db 'Schade um ihn$'
Bemerkung14 db 'Gut gemacht$'
Bemerkung15 db 'Oh$'
Bemerkung16 db 'Achso$'
Bemerkung17 db 'Warum nicht$'
Bemerkung18 db 'Hm$'
Bemerkung19 db 'Nicht schlecht$'
Bemerkung20 db 'Oh weija$'
Bemerkung21 db 'Macht nix$'
;<<<---Optionen--->>>
Koordinaten_anzeigen db 0
Namen_anzeigen db 0
Schachuhr_anzeigen db 0
Zugnotation_anzeigen db 0
Geschlagene_Figuren_anzeigen db 0
Bemerkungen_anzeigen db 0
Optionen_Autosafe db 1
Optionen_Ende db 2
;<<<---Includes--->>>
Include Inc\Font.dat
Include Inc\Text.inc
;<<<---Uninitialisierte Daten--->>>
Figur_ausgew�hlt dw ?
Am_Zug db ?
Figuren_Geschlagen_Z�hlerw dw ?
Figuren_Geschlagen_Z�hlers dw ?
Zug dw ?
Notation_Cursor dw ?
Notation_Cursor2 db ?
Rochade_durchgef�hrt db ?
Spieler1_Uhr dw ?
Spieler2_Uhr dw ?
Anzahl_m�glicher_Z�ge dw ?
Anzahl_m�glicher_Schl�ge dw ?
Anzahl_m�glicher_Deckungen dw ?
Anzahl_ungedeckter_Figuren dw ?
Spielausgang db ?
Im_Schach db ?	;��
;<<<---Rochade--->>>
Turm1w_bewegt db ?
Turm2w_bewegt db ?
K�nigw_bewegt db ?
Turm1s_bewegt db ?
Turm2s_bewegt db ?
K�nigs_bewegt db ?
;<<<---Figuren weiss--->>>
Bauer1w dw ?
Bauer2w dw ?
Bauer3w dw ?
Bauer4w dw ?
Bauer5w dw ?
Bauer6w dw ?
Bauer7w dw ?
Bauer8w dw ?
Turm1w dw ?
Turm2w dw ?
Springer1w dw ?
Springer2w dw ?
L�ufer1w dw ?
L�ufer2w dw ?
Damew dw ?
Dame2w dw ?
Dame3w dw ?
Dame4w dw ?
Dame5w dw ?
Dame6w dw ?
Dame7w dw ?
Dame8w dw ?
Dame9w dw ?
K�nigw dw ?
;<<<---Figuren schwarz--->>>
Bauer1s dw ?
Bauer2s dw ?
Bauer3s dw ?
Bauer4s dw ?
Bauer5s dw ?
Bauer6s dw ?
Bauer7s dw ?
Bauer8s dw ?
Turm1s dw ?
Turm2s dw ?
Springer1s dw ?
Springer2s dw ?
L�ufer1s dw ?
L�ufer2s dw ?
Dames dw ?
Dame2s dw ?
Dame3s dw ?
Dame4s dw ?
Dame5s dw ?
Dame6s dw ?
Dame7s dw ?
Dame8s dw ?
Dame9s dw ?
K�nigs dw ?
;<<<---Cursor--->>>
Cursor db ?,?
Cursoralt db ?,?
;<<<---Puffer--->>>
Temp dw 50 dup(?)
Temp2 dw 50 dup(?)
Temp3 dw 50 dup(?)
Zugliste dw 500 dup(?)
Schlagliste dw 500 dup(?)
Deckungsliste dw 500 dup(?)
Bemerkungenbuffer dw 200 dup (?)