import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        ImportData importData = new ImportData();
        printCars(importData.cars);
        filterByCompany(importData.cars);
    }

    private static void printCars(List<Car> cars) {
        for (int i = 0; i < cars.size(); i++) {
            System.out.println((i+1) + ": " + cars.get(i));
        }
    }

    private static void filterByCompany(List<Car> cars) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Podaj nazwę firmy którą chesz wyfiltrować:");
        String company = scanner.nextLine();

        for (Car car : cars) {
            if (car.company.equalsIgnoreCase(company)) {
                System.out.println(car);
            }
        }
    }
}
