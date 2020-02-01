import { Component } from '@angular/core';
import { Store, select } from '@ngrx/store';
import { Observable } from 'rxjs';
import { selectFeatureCount } from '../selector/counter.selector';
import {INCREMENT, DECREMENT, RESET} from "../counter.reducer";
 
@Component({
  selector: 'app-my-counter',
  templateUrl: './my-counter.component.html',
  styleUrls: ['./my-counter.component.css'],
})
export class MyCounterComponent {
  count$: Observable<number>;
 
  constructor(private store: Store<{ count: number }>) {
    this.count$ = store.pipe(select('count')); // Specified that I want to pipe the values from counter reducer to count$.
  }

  increment() {
    // The JSON object being passed in is THE action in this case.
    this.store.dispatch({type: INCREMENT});
  }
 
  decrement() {
    this.store.dispatch({type: DECREMENT});
  }

  reset() {
    this.store.dispatch({type: RESET});
  }
}