/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_Controller.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_HGraph.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_ResultFromModel.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_CheckStatus.hxx>
#include <Interface_Graph.hxx>
#include <XSControl_TransferReader.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>

void bind_XSControl_TransferReader(py::module &mod){

py::class_<XSControl_TransferReader, opencascade::handle<XSControl_TransferReader>, Standard_Transient> cls_XSControl_TransferReader(mod, "XSControl_TransferReader", "A TransferReader performs, manages, handles results of, transfers done when reading a file (i.e. from entities of an InterfaceModel, to objects for Imagine)");

// Constructors
cls_XSControl_TransferReader.def(py::init<>());

// Fields

// Methods
cls_XSControl_TransferReader.def("SetController", (void (XSControl_TransferReader::*)(const opencascade::handle<XSControl_Controller> &)) &XSControl_TransferReader::SetController, "Sets a Controller. It is required to generate the Actor. Elsewhere, the Actor must be provided directly", py::arg("theControl"));
cls_XSControl_TransferReader.def("SetActor", (void (XSControl_TransferReader::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &XSControl_TransferReader::SetActor, "Sets the Actor directly : this value will be used if the Controller is not set", py::arg("theActor"));
cls_XSControl_TransferReader.def("Actor", (opencascade::handle<Transfer_ActorOfTransientProcess> (XSControl_TransferReader::*)()) &XSControl_TransferReader::Actor, "Returns the Actor, determined by the Controller, or if this one is unknown, directly set. Once it has been defined, it can then be edited.");
cls_XSControl_TransferReader.def("SetModel", (void (XSControl_TransferReader::*)(const opencascade::handle<Interface_InterfaceModel> &)) &XSControl_TransferReader::SetModel, "Sets an InterfaceModel. This causes former results, computed from another one, to be lost (see also Clear)", py::arg("theModel"));
cls_XSControl_TransferReader.def("SetGraph", (void (XSControl_TransferReader::*)(const opencascade::handle<Interface_HGraph> &)) &XSControl_TransferReader::SetGraph, "Sets a Graph and its InterfaceModel (calls SetModel)", py::arg("theGraph"));
cls_XSControl_TransferReader.def("Model", (const opencascade::handle<Interface_InterfaceModel> & (XSControl_TransferReader::*)() const) &XSControl_TransferReader::Model, "Returns the currently set InterfaceModel");
cls_XSControl_TransferReader.def("SetContext", (void (XSControl_TransferReader::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &XSControl_TransferReader::SetContext, "Sets a Context : according to receiving appli, to be interpreted by the Actor", py::arg("theName"), py::arg("theCtx"));
cls_XSControl_TransferReader.def("GetContext", (Standard_Boolean (XSControl_TransferReader::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::GetContext, "Returns the Context attached to a name, if set and if it is Kind of the type, else a Null Handle Returns True if OK, False if no Context", py::arg("theName"), py::arg("theType"), py::arg("theCtx"));
cls_XSControl_TransferReader.def("Context", (NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (XSControl_TransferReader::*)()) &XSControl_TransferReader::Context, "Returns (modifiable) the whole definition of Context Rather for internal use (ex.: preparing and setting in once)");
cls_XSControl_TransferReader.def("SetFileName", (void (XSControl_TransferReader::*)(const Standard_CString)) &XSControl_TransferReader::SetFileName, "Sets a new value for (loaded) file name", py::arg("theName"));
cls_XSControl_TransferReader.def("FileName", (Standard_CString (XSControl_TransferReader::*)() const) &XSControl_TransferReader::FileName, "Returns actual value of file name");
cls_XSControl_TransferReader.def("Clear", (void (XSControl_TransferReader::*)(const Standard_Integer)) &XSControl_TransferReader::Clear, "Clears data, according mode : -1 all 0 nothing done +1 final results +2 working data (model, context, transfer process)", py::arg("theMode"));
cls_XSControl_TransferReader.def("TransientProcess", (const opencascade::handle<Transfer_TransientProcess> & (XSControl_TransferReader::*)() const) &XSControl_TransferReader::TransientProcess, "Returns the currently used TransientProcess It is computed from the model by TransferReadRoots, or by BeginTransferRead");
cls_XSControl_TransferReader.def("SetTransientProcess", (void (XSControl_TransferReader::*)(const opencascade::handle<Transfer_TransientProcess> &)) &XSControl_TransferReader::SetTransientProcess, "Forces the TransientProcess Remark : it also changes the Model and the Actor, from those recorded in the new TransientProcess", py::arg("theTP"));
cls_XSControl_TransferReader.def("RecordResult", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_TransferReader::RecordResult, "Records a final result of transferring an entity This result is recorded as a ResultFromModel, taken from the TransientProcess Returns True if a result is available, False else", py::arg("theEnt"));
cls_XSControl_TransferReader.def("IsRecorded", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::IsRecorded, "Returns True if a final result is recorded for an entity Remark that it can bring no effective result if transfer has completely failed (FinalResult brings only fail messages ...)", py::arg("theEnt"));
cls_XSControl_TransferReader.def("HasResult", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::HasResult, "Returns True if a final result is recorded AND BRINGS AN EFFECTIVE RESULT (else, it brings only fail messages)", py::arg("theEnt"));
cls_XSControl_TransferReader.def("RecordedList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_TransferReader::*)() const) &XSControl_TransferReader::RecordedList, "Returns the list of entities to which a final result is attached (i.e. processed by RecordResult)");
cls_XSControl_TransferReader.def("Skip", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_TransferReader::Skip, "Note that an entity has been required for transfer but no result at all is available (typically : case not implemented) It is not an error, but it gives a specific status : Skipped Returns True if done, False if <ent> is not in starting model", py::arg("theEnt"));
cls_XSControl_TransferReader.def("IsSkipped", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::IsSkipped, "Returns True if an entity is noted as skipped", py::arg("theEnt"));
cls_XSControl_TransferReader.def("IsMarked", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::IsMarked, "Returns True if an entity has been asked for transfert, hence it is marked, as : Recorded (a computation has ran, with or without an effective result), or Skipped (case ignored)", py::arg("theEnt"));
cls_XSControl_TransferReader.def("FinalResult", (opencascade::handle<Transfer_ResultFromModel> (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::FinalResult, "Returns the final result recorded for an entity, as such", py::arg("theEnt"));
cls_XSControl_TransferReader.def("FinalEntityLabel", (Standard_CString (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::FinalEntityLabel, "Returns the label attached to an entity recorded for final, or an empty string if not recorded", py::arg("theEnt"));
cls_XSControl_TransferReader.def("FinalEntityNumber", (Standard_Integer (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::FinalEntityNumber, "Returns the number attached to the entity recorded for final, or zero if not recorded (looks in the ResultFromModel)", py::arg("theEnt"));
cls_XSControl_TransferReader.def("ResultFromNumber", (opencascade::handle<Transfer_ResultFromModel> (XSControl_TransferReader::*)(const Standard_Integer) const) &XSControl_TransferReader::ResultFromNumber, "Returns the final result recorded for a NUMBER of entity (internal use). Null if out of range", py::arg("theNum"));
cls_XSControl_TransferReader.def("TransientResult", (opencascade::handle<Standard_Transient> (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::TransientResult, "Returns the resulting object as a Transient Null Handle if no result or result not transient", py::arg("theEnt"));
cls_XSControl_TransferReader.def("ShapeResult", (TopoDS_Shape (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &) const) &XSControl_TransferReader::ShapeResult, "Returns the resulting object as a Shape Null Shape if no result or result not a shape", py::arg("theEnt"));
cls_XSControl_TransferReader.def("ClearResult", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &XSControl_TransferReader::ClearResult, "Clears recorded result for an entity, according mode <mode> = -1 : true, complete, clearing (erasing result) <mode> >= 0 : simple 'stripping', see ResultFromModel, in particular, 0 for simple internal strip, 10 for all but final result, 11 for all : just label, status and filename are kept Returns True when done, False if nothing was to clear", py::arg("theEnt"), py::arg("theMode"));
cls_XSControl_TransferReader.def("EntityFromResult", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<Standard_Transient> { return self.EntityFromResult(a0); });
cls_XSControl_TransferReader.def("EntityFromResult", (opencascade::handle<Standard_Transient> (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_TransferReader::EntityFromResult, "Returns an entity from which a given result was produced. If <mode> = 0 (D), searches in last root transfers If <mode> = 1, searches in last (root & sub) transfers If <mode> = 2, searches in root recorded results If <mode> = 3, searches in all (root & sub) recordeds <res> can be, either a transient object (result itself) or a binder. For a binder of shape, calls EntityFromShapeResult Returns a Null Handle if <res> not recorded", py::arg("theRes"), py::arg("theMode"));
cls_XSControl_TransferReader.def("EntityFromShapeResult", [](XSControl_TransferReader &self, const TopoDS_Shape & a0) -> opencascade::handle<Standard_Transient> { return self.EntityFromShapeResult(a0); });
cls_XSControl_TransferReader.def("EntityFromShapeResult", (opencascade::handle<Standard_Transient> (XSControl_TransferReader::*)(const TopoDS_Shape &, const Standard_Integer) const) &XSControl_TransferReader::EntityFromShapeResult, "Returns an entity from which a given shape result was produced Returns a Null Handle if <res> not recorded or not a Shape", py::arg("theRes"), py::arg("theMode"));
cls_XSControl_TransferReader.def("EntitiesFromShapeList", [](XSControl_TransferReader &self, const opencascade::handle<TopTools_HSequenceOfShape> & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.EntitiesFromShapeList(a0); });
cls_XSControl_TransferReader.def("EntitiesFromShapeList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_TransferReader::*)(const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Integer) const) &XSControl_TransferReader::EntitiesFromShapeList, "Returns the list of entities from which some shapes were produced : it corresponds to a loop on EntityFromShapeResult, but is optimised", py::arg("theRes"), py::arg("theMode"));
cls_XSControl_TransferReader.def("CheckList", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0) -> Interface_CheckIterator { return self.CheckList(a0); });
cls_XSControl_TransferReader.def("CheckList", (Interface_CheckIterator (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_TransferReader::CheckList, "Returns the CheckList resulting from transferring <ent>, i.e. stored in its recorded form ResultFromModel (empty if transfer successful or not recorded ...)", py::arg("theEnt"), py::arg("theLevel"));
cls_XSControl_TransferReader.def("HasChecks", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &XSControl_TransferReader::HasChecks, "Returns True if an entity (with a final result) has checks : - failsonly = False : any kind of check message - failsonly = True : fails only Returns False if <ent> is not recorded", py::arg("theEnt"), py::arg("FailsOnly"));
cls_XSControl_TransferReader.def("CheckedList", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.CheckedList(a0); });
cls_XSControl_TransferReader.def("CheckedList", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0, const Interface_CheckStatus a1) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.CheckedList(a0, a1); });
cls_XSControl_TransferReader.def("CheckedList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Interface_CheckStatus, const Standard_Boolean) const) &XSControl_TransferReader::CheckedList, "Returns the list of starting entities to which a given check status is attached, IN FINAL RESULTS <ent> can be an entity, or the model to query all entities Below, 'entities' are, either <ent> plus its sub-transferred, or all the entities of the model", py::arg("theEnt"), py::arg("WithCheck"), py::arg("theResult"));
cls_XSControl_TransferReader.def("BeginTransfer", (Standard_Boolean (XSControl_TransferReader::*)()) &XSControl_TransferReader::BeginTransfer, "Defines a new TransferProcess for reading transfer Returns True if done, False if data are not properly defined (the Model, the Actor for Read)");
cls_XSControl_TransferReader.def("Recognize", (Standard_Boolean (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_TransferReader::Recognize, "Tells if an entity is recognized as a valid candidate for Transfer. Calls method Recognize from the Actor (if known)", py::arg("theEnt"));
cls_XSControl_TransferReader.def("TransferOne", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0) -> Standard_Integer { return self.TransferOne(a0); });
cls_XSControl_TransferReader.def("TransferOne", (Standard_Integer (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &XSControl_TransferReader::TransferOne, "Commands the transfer on reading for an entity to data for Imagine, using the selected Actor for Read Returns count of transferred entities, ok or with fails (0/1) If <rec> is True (D), the result is recorded by RecordResult", py::arg("theEnt"), py::arg("theRec"));
cls_XSControl_TransferReader.def("TransferList", [](XSControl_TransferReader &self, const opencascade::handle<TColStd_HSequenceOfTransient> & a0) -> Standard_Integer { return self.TransferList(a0); });
cls_XSControl_TransferReader.def("TransferList", (Standard_Integer (XSControl_TransferReader::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Boolean)) &XSControl_TransferReader::TransferList, "Commands the transfer on reading for a list of entities to data for Imagine, using the selected Actor for Read Returns count of transferred entities, ok or with fails (0/1) If <rec> is True (D), the results are recorded by RecordResult", py::arg("theList"), py::arg("theRec"));
cls_XSControl_TransferReader.def("TransferRoots", (Standard_Integer (XSControl_TransferReader::*)(const Interface_Graph &)) &XSControl_TransferReader::TransferRoots, "Transfers the content of the current Interface Model to data handled by Imagine, starting from its Roots (determined by the Graph <G>), using the selected Actor for Read Returns the count of performed root transfers (i.e. 0 if none) or -1 if no actor is defined", py::arg("theGraph"));
cls_XSControl_TransferReader.def("TransferClear", [](XSControl_TransferReader &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.TransferClear(a0); });
cls_XSControl_TransferReader.def("TransferClear", (void (XSControl_TransferReader::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &XSControl_TransferReader::TransferClear, "Clears the results attached to an entity if <ents> equates the starting model, clears all results", py::arg("theEnt"), py::arg("theLevel"));
cls_XSControl_TransferReader.def("PrintStats", [](XSControl_TransferReader &self, const Standard_Integer a0) -> void { return self.PrintStats(a0); });
cls_XSControl_TransferReader.def("PrintStats", (void (XSControl_TransferReader::*)(const Standard_Integer, const Standard_Integer) const) &XSControl_TransferReader::PrintStats, "Prints statistics on current Trace File, according <what> and <mode>. See PrintStatsProcess for details", py::arg("theWhat"), py::arg("theMode"));
cls_XSControl_TransferReader.def("LastCheckList", (Interface_CheckIterator (XSControl_TransferReader::*)() const) &XSControl_TransferReader::LastCheckList, "Returns the CheckList resulting from last TransferRead i.e. from TransientProcess itself, recorded from last Clear");
cls_XSControl_TransferReader.def("LastTransferList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_TransferReader::*)(const Standard_Boolean) const) &XSControl_TransferReader::LastTransferList, "Returns the list of entities recorded as lastly transferred i.e. from TransientProcess itself, recorded from last Clear If <roots> is True , considers only roots of transfer If <roots> is False, considers all entities bound with result", py::arg("theRoots"));
cls_XSControl_TransferReader.def("ShapeResultList", (const opencascade::handle<TopTools_HSequenceOfShape> & (XSControl_TransferReader::*)(const Standard_Boolean)) &XSControl_TransferReader::ShapeResultList, "Returns a list of result Shapes If <rec> is True , sees RecordedList If <rec> is False, sees LastTransferList (last ROOT transfers) For each one, if it is a Shape, it is cumulated to the list If no Shape is found, returns an empty Sequence", py::arg("theRec"));
cls_XSControl_TransferReader.def_static("PrintStatsProcess_", [](const opencascade::handle<Transfer_TransientProcess> & a0, const Standard_Integer a1) -> void { return XSControl_TransferReader::PrintStatsProcess(a0, a1); });
cls_XSControl_TransferReader.def_static("PrintStatsProcess_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const Standard_Integer, const Standard_Integer)) &XSControl_TransferReader::PrintStatsProcess, "This routines prints statistics about a TransientProcess It can be called, by a TransferReader, or isolately Prints are done on the default trace file <what> defines what kind of statistics are to be printed : 0 : basic figures 1 : root results 2 : all recorded (roots, intermediate, checked entities) 3 : abnormal records 4 : check messages (warnings and fails) 5 : fail messages", py::arg("theTP"), py::arg("theWhat"), py::arg("theMode"));
cls_XSControl_TransferReader.def_static("PrintStatsOnList_", [](const opencascade::handle<Transfer_TransientProcess> & a0, const opencascade::handle<TColStd_HSequenceOfTransient> & a1, const Standard_Integer a2) -> void { return XSControl_TransferReader::PrintStatsOnList(a0, a1, a2); });
cls_XSControl_TransferReader.def_static("PrintStatsOnList_", (void (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Integer, const Standard_Integer)) &XSControl_TransferReader::PrintStatsOnList, "Works as PrintStatsProcess, but displays data only on the entities which are in <list> (filter)", py::arg("theTP"), py::arg("theList"), py::arg("theWhat"), py::arg("theMode"));
cls_XSControl_TransferReader.def_static("get_type_name_", (const char * (*)()) &XSControl_TransferReader::get_type_name, "None");
cls_XSControl_TransferReader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_TransferReader::get_type_descriptor, "None");
cls_XSControl_TransferReader.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_TransferReader::*)() const) &XSControl_TransferReader::DynamicType, "None");

// Enums

}