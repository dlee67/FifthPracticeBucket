import { Component, OnInit } from '@angular/core';
import { SpinnerOverlayService } from '../../services/service-overlay.service'

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss']
})
export class HeaderComponent implements OnInit {

  constructor(private spinnerService: SpinnerOverlayService) { }

  ngOnInit(): void {
    this.spinnerService.show();
  }

}
