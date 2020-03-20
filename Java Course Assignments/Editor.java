/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.effect.Reflection;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.web.HTMLEditor;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javax.swing.JFrame;

/**
 *
 * @author FatmaGomaa
 */
public class Editor extends Application {
    String bufferString;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Application.launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        MenuBar bar = new MenuBar();
        Menu file = new Menu("File");

        MenuItem newItem = new MenuItem("new");
        MenuItem openItem = new MenuItem("open");
        MenuItem saveItem = new MenuItem("save");
        MenuItem exitItem = new MenuItem("exit");
        exitItem.setAccelerator(KeyCombination.keyCombination("Esc"));

        SeparatorMenuItem separator = new SeparatorMenuItem();
        SeparatorMenuItem separator1 = new SeparatorMenuItem();

        Menu edit = new Menu("Edit");
        MenuItem cutItem = new MenuItem("cut");
        cutItem.setAccelerator(KeyCombination.keyCombination("Ctrl+x"));
        MenuItem copyItem = new MenuItem("copy");
        copyItem.setAccelerator(KeyCombination.keyCombination("Ctrl+c"));
        MenuItem pasteItem = new MenuItem("paste");
        pasteItem.setAccelerator(KeyCombination.keyCombination("Ctrl+v"));
        MenuItem deleteItem = new MenuItem("delete");
        deleteItem.setAccelerator(KeyCombination.keyCombination("Delete"));

        TextArea text = new TextArea();

        file.getItems().addAll(newItem, openItem, saveItem, separator, exitItem);
        edit.getItems().addAll(cutItem, copyItem, pasteItem, separator1, deleteItem);
        bar.getMenus().addAll(file, edit);

        BorderPane pane = new BorderPane();
        // FlowPane flow = new FlowPane();
        //flow.setOrientation(Orientation.HORIZONTAL);
        //flow.getChildren().addAll(bar, new HTMLEditor());
        pane.setTop(bar);
        //pane.getChildren().add(new HTMLEditor());
        pane.setCenter(text);
        Scene scene = new Scene(pane, 800, 600);
        primaryStage.setTitle("Homemade Notepad++");
        primaryStage.setScene(scene);
        primaryStage.show();

        newItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                text.clear();
            }
        });

        openItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                FileChooser fileChooser = new FileChooser();
                File file = fileChooser.showOpenDialog(primaryStage);
                if (file != null) {
                    text.setText(readFile(file));
                }

            }

            private String readFile(File file) {
                StringBuilder stringBuffer = new StringBuilder();
                BufferedReader bufferedReader = null;

                try {

                    bufferedReader = new BufferedReader(new FileReader(file));

                    String text;
                    while ((text = bufferedReader.readLine()) != null) {
                        stringBuffer.append(text);
                        stringBuffer.append("\n");
                        
                    }

                } catch (FileNotFoundException ex) {
                    Logger.getLogger(Editor.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(Editor.class.getName()).log(Level.SEVERE, null, ex);
                } finally {
                    try {
                        bufferedReader.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Editor.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

                return stringBuffer.toString();
            }

        });

        saveItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                FileChooser fileChooser = new FileChooser();

                FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");
                fileChooser.getExtensionFilters().add(extFilter);

                File file = fileChooser.showSaveDialog(primaryStage);

                if (file != null) {
                    SaveFile(text, file);
                }
            }

            private void SaveFile(TextArea text, File file) {
                try {
                    FileWriter fileWriter = null;

                    fileWriter = new FileWriter(file);
                    fileWriter.write(text.getText());
                    fileWriter.close();
                } catch (IOException ex) {
                    Logger.getLogger(Editor.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        
        
        copyItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                bufferString = text.getSelectedText();
            }
        });
        
         pasteItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                text.appendText(bufferString);
            }
        });
         
        cutItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                bufferString = text.getSelectedText();
                text.setText(text.getText().replace(text.getSelectedText(),""));
            }
        });
        
        exitItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                primaryStage.close();
            }
        });
        
        deleteItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent t) {
                text.deletePreviousChar();
            }
        });
        
    }

}
