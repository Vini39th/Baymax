package Projeto;

public class Passageiro {
	
	private String nome;
	private String cpf;
	
	public Passageiro(String nome, String cpf) {
		this.nome = nome;
		this.cpf = cpf;
	}

	public String getNome() {
		return nome;
	}

	public String getCpf() {
		return cpf;
	}
}

	//public void setCPF(String cpf) throws Exception{
		//if(this.validaCpf(cpf)) {
	//		this.cpf = cpf;
		//} else {
//			throw new Exception("CPF inválido");
	//	}
	//}

	
	//private boolean validaCpf(String cpf) {
		//if();
	//}

