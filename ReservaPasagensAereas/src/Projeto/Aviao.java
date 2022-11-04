package Projeto;

public class Aviao extends Aeronave {
	
	public Passageiro[][] lugares;
	
	public Aviao (String modelo, int fileiras, int assentos) {
		
		super(modelo);
		this.lugares = new Passageiro[fileiras][assentos];
	}
	
	public boolean verificaLugarOcupado(int fileira, int assento) {
		return this.lugares[fileira][assento] != null;
	}

	public Passageiro getPassageiro(int fileira, int assento) {
		return this.lugares[fileira][assento];
	}

	public void setPassageiro(int fileira, int assento, Passageiro passageiro) {
		this.lugares[fileira][assento] = passageiro;
	}
	
	public String toString() {
		return this.modelo;
	}
}
