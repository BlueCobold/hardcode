Regeltext db 0
 db '��������������������Ļ',0
 db '� Regelwerk Chess32k �',0
 db '�����������������������������������������������������������������������������Ļ',0
 db '� Zu ziehen sind die Figuren wie in einem normalen Schachspiel, f�r alle, die �',0
 db '� nicht wissen, was das sein soll, hier die Regeln f�r des Spiels:            �',0
 db '� 1, Mit Wei� beginnend wird abwechselnd gezogen.                             �',0
 db '� 2, Schach ist die Strategie in Person, also Zeit lassen und nachdenken!     �',0
 db '� 3, Eine Figur schl�gt die gegnerische, wenn sie auf deren Feld kommt. Aber  �',0
 db '�    jeder Stratege wei�, da� wenn seine Figur wegen der anderen verloren     �',0
 db '�    gehen kann, die Priorit�t eine wichtige Rolle spielt.                    �',0
 db '� 4, Ist der K�nig [',4,'] bedroht, also im "Schach", so mu� dieser zuerst von    �',0
 db '�    dieser Bedrohung entbunden werden, das hei�t, da� er entweder weggezogen �',0
 db '�    , eine Figur dazwischen gestellt oder aber der Angreifer geschlagen      �',0
 db '�    werden mu�.                                                              �',0
 db '� 5, Kann der K�nig [',4,'] nicht aus einer mi�lichen Lage befreit werden, so hat �',0
 db '�    der Gegner durch "Schach Matt" gewonnen.                                 �',0
 db '� 6, �u�erst n�tzlich ist die Rochade, ein Zug, der vom K�nig [',4,'] und vom     �',0
 db '�    Turm [',6,'] nur dann ausgef�hrt werden kann, wenn beide im Spiel noch nicht �',0
 db '�    gezogen wurden. Gegenstand des Zuges ist die 2-Felderbewegung des K�nigs �',0
 db '�    zum Turm und das �berspringen des K�nigs vom Turm, sozusagen das         �',0
 db '�    Tauschen der Seiten!                                                     �',0
 db '� 7, Jede Figur wird unabh�ngig von den anderen und unterschiedlich bewegt:   �',0
 db '� ',1,'  Der Bauer    ',26,' Er kann anfangs ein oder zwei Schritte geradeaus ziehen,  �',0
 db '�                   zieht aber dann immer nur einen Schritt nach vorn, nicht  �',0
 db '�                   zur�ck                                                    �',0
 db '�                 ',26,' Er schl�gt diagonal direkt den Gegner                     �',0
 db '�                 ',26,' Er besitzt Priorit�t 1                                    �',0
Textende db '�                 ',26,' Es findet eine "Bauernumwandlung" statt, wenn der         �',0
 db '�                   Bauer den gegen�berliegenden Brettrand erreicht. Dabei    �',0
 db '�                   wird er gegen eine andere, neue Figur getauscht. Man kann �',0
 db '�                   also theoretisch 9 Damen gleichzeitig auf dem Schachbrett �',0
 db '�                   haben! Die neue Figur darf nur kein K�nig sein.           �',0
 db '�                 ',26,' "En passant" schl�gt er, wenn ein gegnerischer Bauer      �',0
 db '�                   anf�nglich 2 Schritte nach vorn zieht und danach neben    �',0
 db '�                   deinem stehen bleibt. Genau dann kann man ihn schlagen,   �',0
 db '�                   indem man seinen Bauern schr�g genau hinter den Gegner    �',0
 db '�                   r�ckt                                                     �',0
 db '� ',2,'  Der L�ufer   ',26,' Er zieht und schl�gt diagonal in alle Richtungen          �',0
 db '�                 ',26,' Er besitzt Priorit�t 2                                    �',0
 db '� ',3,'  Der Springer ',26,' Er zieht und schl�gt zwei Schritte geradeaus, dann einen  �',0
 db '�                   zur Seite                                                 �',0
 db '�                 ',26,' kann �ber alle Figuren hinwegspringen                     �',0
 db '�                 ',26,' Er besitzt Priorit�t 2                                    �',0
 db '� ',6,' -  Der Turm   ',26,' Er zieht und schl�gt Vertikal oder Horizontal             �',0
 db '�                 ',26,' Er besitzt Priorit�t 3                                    �',0
 db '� ',5,' -  Die Dame   ',26,' Zieht und schl�gt in alle Richtungen geradlinig           �',0
 db '�                 ',26,' Sie besitzt Priorit�t 4                                   �',0
 db '� ',4,' -  Der K�nig  ',26,' Kann einen Schritt in alle Richtungen setzen              �',0
 db '�                 ',26,' Er besitzt allerh�chste Priorit�t                         �',0
 db '�����������������������������������������������������������������������������ļ',0

