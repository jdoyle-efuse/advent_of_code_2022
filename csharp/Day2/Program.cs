var part1_total = 0;
var part2_total = 0;

File.ReadAllLines("input.txt").ToList().ForEach(x =>
{
    var pair = x.Split(' ');
    part1_total += compare_part1(pair[0], pair[1]);
    part2_total += compare_part2(pair[0], pair[1]);
});

Console.WriteLine(part1_total);
Console.WriteLine(part2_total);

int compare_part1(string opponent, string mine)
{
    var r = mine == "X" ? 1 : mine == "Y" ? 2 : 3;
    var s = opponent + mine;
    if (s == "AX") r += 3;
    if (s == "AY") r += 6;
    if (s == "AZ") r += 0;
    if (s == "BX") r += 0;
    if (s == "BY") r += 3;
    if (s == "BZ") r += 6;
    if (s == "CX") r += 6;
    if (s == "CY") r += 0;
    if (s == "CZ") r += 3;
    return r;
}

int compare_part2(string opponent, string mine)
{
    var r = mine == "X" ? 0 : mine == "Y" ? 3 : 6;
    var s = opponent + mine;
    if (s == "AX") r += 3;
    if (s == "AY") r += 1;
    if (s == "AZ") r += 2;
    if (s == "BX") r += 1;
    if (s == "BY") r += 2;
    if (s == "BZ") r += 3;
    if (s == "CX") r += 2;
    if (s == "CY") r += 3;
    if (s == "CZ") r += 1;
    return r;
}