public interface ComputerBuilder {
    void buildCpu();
    void buildRam();
    void buildStorage();
    void buildGpu();
    Computer getResult();
}

// Concrete builder
class OfficeComputerBuilder implements ComputerBuilder {
    private final Computer computer = new Computer();

    @Override
    public void buildCpu() { computer.setCpu("Intel i3"); }

    @Override
    public void buildRam() { computer.setRam("8GB"); }

    @Override
    public void buildStorage() { computer.setStorage("256GB SSD"); }

    @Override
    public void buildGpu() { computer.setGpu(false); }

    @Override
    public Computer getResult() { return computer; }
}

// Concrete builder
class GamingComputerBuilder implements ComputerBuilder {
    private final Computer computer = new Computer();

    @Override
    public void buildCpu() { computer.setCpu("Intel i9"); }

    @Override
    public void buildRam() { computer.setRam("32GB"); }

    @Override
    public void buildStorage() { computer.setStorage("2TB SSD"); }

    @Override
    public void buildGpu() { computer.setGpu(true); }

    @Override
    public Computer getResult() { return computer; }
}