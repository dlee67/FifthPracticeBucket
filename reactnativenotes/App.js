import React from 'react';
import {createAppContainer} from 'react-navigation';
import {createStackNavigator} from 'react-navigation-stack';
import HomeScreen from './Screens/AddNoteScreen';
import {AddNoteScreen} from './Screen/ModifyNoteScreen';
import {NoteProvider} from './Context/NodeContext';

const RootStack = createStackNavigator(
  {
    Home: {
      screen: HomeScreen
    },
    AddNoteScreen: {
      screen: AddNoteScreen
    },
    ModNote: {
      screen: ModifyNoteScreen
    }
  },
  {
    initialRouteName: 'Home',
    headerMode: 'none',
  }
);

const AppContainer = createAppContainer(RootStack);

const App = () => (
  <NoteProvider>
    <AppContainer/>
  </NoteProvider>
);

export default App;