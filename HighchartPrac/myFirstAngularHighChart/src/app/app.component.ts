import { Component } from '@angular/core';
import * as Highcharts from 'highcharts';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'myHighChartsApp';
  highcharts = Highcharts;
  // https://stackblitz.com/edit/highcharts-angular-basic-line-dpqftl
  data1 = [500, 700, 555, 444, 777, 877, 944, 567, 666, 789, 456, 654];
  data2 = [677, 455, 677, 877, 455, 778, 888, 567, 785, 488, 567, 654];
  name1= "ItSolutionStuff.com";

  chartOptions: Highcharts.Options = {
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