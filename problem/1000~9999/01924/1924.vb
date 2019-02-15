Imports System

Module Program
    Sub Main(args As String())
        Dim s As String() = Console.ReadLine().Split(" ")
        Dim m As Integer = Integer.Parse(s(0))
        Dim d As Integer = Integer.Parse(s(1))
        Dim sum As Integer = 0
        Dim mon31 As String() = {"1", "3", "5", "7", "8", "10", "12"}
        Dim mon30 As String() = {"4", "6", "9", "11"}
        Dim i As Integer

        sum += d - 1

        For i = 1 To m - 1
            If contain(mon31, i.ToString) Then
                sum += 31
            ElseIf contain(mon30, i.ToString) Then
                sum += 30
            Else
                sum += 28
            End If
        Next

        Select Case sum Mod 7
            Case 0
                Console.WriteLine("MON")
            Case 1
                Console.WriteLine("TUE")
            Case 2
                Console.WriteLine("WED")
            Case 3
                Console.WriteLine("THU")
            Case 4
                Console.WriteLine("FRI")
            Case 5
                Console.WriteLine("SAT")
            Case 6
                Console.WriteLine("SUN")
        End Select
    End Sub

Function contain(a As String(), b As String) as Integer
        Dim item As String
        For Each item In a
            If item = b Then Return 1
        Next
        Return 0
    End Function
End Module
