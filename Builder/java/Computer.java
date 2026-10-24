public class Computer {
    private String cpu;
    private String ram;
    private String storage;
    private boolean hasGpu;

    public void setCpu(String cpu) { this.cpu = cpu; }
    public void setRam(String ram) { this.ram = ram; }
    public void setStorage(String storage) { this.storage = storage; }
    public void setGpu(boolean hasGpu) { this.hasGpu = hasGpu; }

    public void show() {
        System.out.println("Computer: CPU=" + cpu
                + ", RAM=" + ram
                + ", Storage=" + storage
                + ", GPU=" + (hasGpu ? "yes" : "no"));
    }

    static void main() {
        OfficeComputerBuilder officeBuilder = new OfficeComputerBuilder();
        Director officeDirector = new Director(officeBuilder);
        officeDirector.construct();
        officeBuilder.getResult().show();

        GamingComputerBuilder gamingBuilder = new GamingComputerBuilder();
        Director gamingDirector = new Director(gamingBuilder);
        gamingDirector.construct();
        gamingBuilder.getResult().show();
    }
}

// Director
class Director {
    private final ComputerBuilder builder;

    public Director(ComputerBuilder builder) {
        this.builder = builder;
    }

    public void construct() {
        builder.buildCpu();
        builder.buildRam();
        builder.buildStorage();
        builder.buildGpu();
    }
}