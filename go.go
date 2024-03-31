package main

import "fmt"

const (
	dollarToRupiahRate = 14000
	maxDollarExchange  = 100
	minDollarExchange  = 1
)

func main() {
	var dollar int
	fmt.Print("Masukkan Dollar Anda : ")
	fmt.Scanf("%d", &dollar)
	saldoDollar := dollar
	fmt.Println("Saldo dollar awal : ", saldoDollar)
	exchangeDollarToRupiah(saldoDollar)
}

func exchangeDollarToRupiah(saldoDollar int) int {
	if saldoDollar < maxDollarExchange && saldoDollar > minDollarExchange {
		fmt.Println("saldo rupiah setelah di konversi adalah : ", saldoDollar*dollarToRupiahRate)
	} else if saldoDollar > maxDollarExchange {
		fmt.Println("Maaf, saldo dollar anda melebihi dari batas maksimal kami")
	} else if saldoDollar < minDollarExchange {
		fmt.Println("Maaf, saldo dollar anda kurang dari batas minimal kami")
	} else {
		fmt.Println("ERROR")
	}
	return saldoDollar
}
