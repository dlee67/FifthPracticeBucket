import { Component } from '@angular/core';
import * as Highcharts from 'highcharts';

// These four lines are what's creating the hamburger dropdown.
import HC_exporting from 'highcharts/modules/exporting';
import HC_FullScreen from 'highcharts/modules/full-screen';
HC_exporting(Highcharts);
HC_FullScreen(Highcharts);

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'myHighChartsApp';
  highcharts = Highcharts;
  // https://stackblitz.com/edit/highcharts-angular-basic-line-dpqftl
  // https://www.highcharts.com/forum/viewtopic.php?t=35278
  // In order to embedd a button inside a highchart, you have to "workaround it."
  // https://www.highcharts.com/docs/stock/stock-tools
  // Highchart has something called stock.
  // https://shop.highcharts.com/?_ga=2.12476148.1790198598.1648109225-758429516.1648109225
  // Uhh ... is this something you have to pay?
  data1 = [500, 700, 555, 444, 777, 877, 944, 567, 666, 789, 456, 654];
  data2 = [677, 455, 677, 877, 455, 778, 888, 567, 785, 488, 567, 654];
  name1= "ItSolutionStuff.com";

  chartOptions: Highcharts.Options = {
    chart: {
      zoomType: 'xy'
    },
    title: {
      text: "Monthly Site Visitor"
    },
    xAxis: {
      categories: [
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
      ]
    },
    yAxis: {
      title: {
        text: "Visitors"
      }
    },
    series: [
      {
        name: this.name1,
        type: "spline",
        data: this.data1
      },
      {
        type: "spline",
        data: this.data2,
        name: "Nicesnippets.com",
        color: "#3183F5"
      }
    ]
  };
}