public class ITF_03_while {

    public static void main(String[] args) {

        // while = atat timp cat conditia inca e adevarata, execut codul dintre acolade

        int benzina_ramasa = 7;
        // cat timp mai avem benzina, putem accelera, masina merge
        while (benzina_ramasa > 0) {
            System.out.println("Vruuum! Vruuum!");
            // in timp ce masina accelereaza, se consuma 1L de benzina
            benzina_ramasa = benzina_ramasa - 1;
            if (benzina_ramasa > 0) {
              System.out.println("Au mai ramas " + benzina_ramasa + " litri de benzina");
            }
        }

        // nu mai avem benzina
        System.out.println("STOP! Nu mai este benzina in rezervor!");

        int nr_vieti = 3; // Super Mario are 3 vieti

        while (nr_vieti > 0) {
            // De fiecare data cand moare, Super Mario pierde o viata
            nr_vieti = nr_vieti - 1;
            System.out.println("Nr vieti ramase: " + nr_vieti);
        }
        // Super Mario nu mai are vieti ramase
        System.out.println("Game Over!");
        /* exercitiu:
        Super mario are 3 vieti
        De fiecare data cand moare ii scadem o viata
        Dupa ce nu mai are vieti afisam "Game Over!"
         */
    }
}
