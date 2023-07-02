public class Car {
    public String company;
    public String model;
    public int year;
    public int yearStop;

    public Car(String company, String model, int year, int yearStop) {
        this.company = company;
        this.model = model;
        this.year = year;
        this.yearStop = yearStop;
    }

    @Override
    public String toString() {
        return "Car{" +
                "company='" + company + '\'' +
                ", model='" + model + '\'' +
                ", year=" + year +
                ", yearStop=" + yearStop +
                '}';
    }
}