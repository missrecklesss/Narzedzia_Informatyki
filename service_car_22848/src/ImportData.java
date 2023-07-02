import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ImportData {
    List<Car> cars = new ArrayList<>();

    public ImportData() {
        try (InputStream inputStream = getClass().getResourceAsStream("/car_list_c10.txt");
             BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {

            String line;
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                Car car = new Car(data[0], data[1], Integer.parseInt(data[2]), Integer.parseInt(data[3]));
                cars.add(car);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public List<Car> getCars() {
        return cars;
    }
}
