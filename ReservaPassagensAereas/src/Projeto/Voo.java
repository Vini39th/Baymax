package Projeto;

public class Voo {
	
	private Aviao aeronave;
	private int nro;
	private String data;
	private String hora;
	
	public Voo(Aviao aeronave, int nro, String data, String hora) throws Exception {
		if(aeronave == null)
			throw new Exception("Avião não pode ser nulo");
		this.aeronave = aeronave;
		this.nro = nro;
		this.data = data;
		this.hora = hora;
	}

	public int getNro() {
		return nro;
	}

	public String getData() {
		return data;
	}

	public String getHora() {
		return hora;
	}

}
