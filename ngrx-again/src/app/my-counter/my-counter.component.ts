import { Component } from '@angular/core';
import { Store } from '@ngrx/store';
import { Observable } from 'rxjs';
import { increment, decrement, reset } from '../counter.actions';
import { saveName } from '../name.actions'

@Component({
  selector: 'app-my-counter',
  templateUrl: './my-counter.component.html',
  styleUrls: ['./my-counter.component.css'],
})
export class MyCounterComponent {
  count$: Observable<number>;
  name$: Observable<string>;

  constructor(private store: Store<{ count: number }>, 
              private nameStore: Store<{ name: string }>) {
    this.count$ = store.select('count');
    this.name$ = nameStore.select('name');
  }

  increment() {
    this.store.dispatch(increment());
  }

  decrement() {
    this.store.dispatch(decrement());
  }

  reset() {
    this.store.dispatch(reset());
  }

  changeName() {
    // Notice how the object {name: "Some Name"} matches the props in name.actions.
    this.nameStore.dispatch(saveName({name: "Some Name"}));
  }
}