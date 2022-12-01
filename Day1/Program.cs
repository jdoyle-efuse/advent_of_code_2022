// See https://aka.ms/new-console-template for more information

var inputLines = File.ReadAllLines(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "input.txt"));

var segmentTotals = new List<int>();
var runningTotal = 0;

foreach (var line in inputLines)
{
    if (line.Trim() == "")
    {
        segmentTotals.Add(runningTotal);
        runningTotal = 0;
    }
    else
    {
        runningTotal += Convert.ToInt32(line);
    }
}

Console.WriteLine(segmentTotals.Max());

segmentTotals = segmentTotals.OrderByDescending(x => x).ToList();

Console.WriteLine(segmentTotals[0] + segmentTotals[1] + segmentTotals[2]);
