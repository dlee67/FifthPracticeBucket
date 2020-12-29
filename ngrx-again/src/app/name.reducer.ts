import { createReducer, on } from '@ngrx/store';
import { saveName } from './name.actions'
import { Name } from './name.model'

export const initialName = 'Nemo';

const _nameReducer = createReducer(
    initialName,
    on(saveName, (state, { Name }) => Name )
);

export function nameReducer(state, action) {
    return _nameReducer(state, action);
}