package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
)

func main() {

	var fileLines []string = readLines("input.txt")
	var runningTotal int = 0
	var allTotals []int

	for i := 0; i < len(fileLines); i++ {
		var line string = fileLines[i]
		if line == "" {
			allTotals = append(allTotals, runningTotal)
			runningTotal = 0
		} else {
			intVal, intErr := strconv.Atoi(line)
			if intErr != nil {
				log.Fatal(intErr)
			}
			runningTotal += intVal
		}
	}

	if runningTotal > 0 {
		allTotals = append(allTotals, runningTotal)
	}

	fmt.Println(maxSliceValue(allTotals))

	sort.Ints(allTotals)

	fmt.Println(allTotals[len(allTotals)-1] + allTotals[len(allTotals)-2] + allTotals[len(allTotals)-3])
}

func maxSliceValue(v []int) (m int) {
	if len(v) > 0 {
		m = v[0]
	}
	for i := 1; i < len(v); i++ {
		if v[i] > m {
			m = v[i]
		}
	}
	return
}

func readLines(filePath string) (fileLines []string) {
	file, err := os.Open(filePath)
	if err != nil {
		log.Fatal(err)
	}
	defer func(file *os.File) {
		err := file.Close()
		if err != nil {
			log.Fatal(err)
		}
	}(file)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		fileLines = append(fileLines, scanner.Text())
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	return
}
