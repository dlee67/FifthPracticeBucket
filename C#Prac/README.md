https://docs.microsoft.com/en-us/dotnet/core/tutorials/with-visual-studio-code

The above got me set up for hello world.

##This stood out to me when learning about C#:

```
switch (shape)
{
    case (int w, int h) when w < h: return "Portrait";
    case (int w, int h) when w > h: return "Landscape";
    case (int _, int _): return "Square";
    default: return "Unknown";
}

//Taken from Programming C# 8.0
```

The above is pretty neat. They call the above concept a pattern.