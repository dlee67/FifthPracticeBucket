import { Component } from '@angular/core';
import { Store, select } from '@ngrx/store';
import { Observable } from 'rxjs';
import { AppState, selectFeatureCount } from '../selector/counter.selector';
import {INCREMENT, DECREMENT, RESET} from "../counter.reducer";
import {NAME} from "../name.reducer"; 

@Component({
  selector: 'app-my-counter',
  templateUrl: './my-counter.component.html',
  styleUrls: ['./my-counter.component.css'],
})
export class MyCounterComponent {
  count$: Observable<number>;
  name$: Observable<string>;
 
  constructor(private counterStore: Store<AppState>, private nameStore: Store<{name: string}>) {
    this.count$ = counterStore.pipe(select(selectFeatureCount, 0)); // Specified that I want to pipe the values from counter reducer to count$.
    this.name$ = nameStore.pipe(select('name')); // At the moment, doing a dispatch affects both the name and the counter reducer.
  }

  increment() {
    // The JSON object being passed in is THE action in this case.
    this.counterStore.dispatch({type: INCREMENT});
  }
 
  decrement() {
    this.counterStore.dispatch({type: DECREMENT});
  }

  reset() {
    this.counterStore.dispatch({type: RESET});
  }

  name() {
    this.nameStore.dispatch({type: NAME});
  }
}