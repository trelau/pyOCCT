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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <IFSelect_PrintCount.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <XSControl_Reader.hxx>

void bind_XSControl_Reader(py::module &mod){

py::class_<XSControl_Reader, std::unique_ptr<XSControl_Reader>> cls_XSControl_Reader(mod, "XSControl_Reader", "A groundwork to convert a shape to data which complies with a particular norm. This data can be that of a whole model or that of a specific list of entities in the model. You specify the list using a single selection or a combination of selections. A selection is an operator which computes a list of entities from a list given in input. To specify the input, you can use: - A predefined selection such as 'xst-transferrable-roots' - A filter based on a signature. A signature is an operator which returns a string from an entity according to its type. For example: - 'xst-type' (CDL) - 'iges-level' - 'step-type'. A filter can be based on a signature by giving a value to be matched by the string returned. For example, 'xst-type(Curve)'. If no list is specified, the selection computes its list of entities from the whole model. To use this class, you have to initialize the transfer norm first, as shown in the example below. Example: Control_Reader reader; IFSelect_ReturnStatus status = reader.ReadFile (filename.); When using IGESControl_Reader or STEPControl_Reader - as the above example shows - the reader initializes the norm directly. Note that loading the file only stores the data. It does not translate this data. Shapes are accumulated by successive transfers. The last shape is cleared by: - ClearShapes which allows you to handle a new batch - TransferRoots which restarts the list of shapes from scratch.");

// Constructors
cls_XSControl_Reader.def(py::init<>());
cls_XSControl_Reader.def(py::init<const Standard_CString>(), py::arg("norm"));
cls_XSControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_XSControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_XSControl_Reader.def_static("operator new_", (void * (*)(size_t)) &XSControl_Reader::operator new, "None", py::arg("theSize"));
// cls_XSControl_Reader.def_static("operator delete_", (void (*)(void *)) &XSControl_Reader::operator delete, "None", py::arg("theAddress"));
// cls_XSControl_Reader.def_static("operator new[]_", (void * (*)(size_t)) &XSControl_Reader::operator new[], "None", py::arg("theSize"));
// cls_XSControl_Reader.def_static("operator delete[]_", (void (*)(void *)) &XSControl_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_XSControl_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &XSControl_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSControl_Reader.def_static("operator delete_", (void (*)(void *, void *)) &XSControl_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_XSControl_Reader.def("SetNorm", (Standard_Boolean (XSControl_Reader::*)(const Standard_CString)) &XSControl_Reader::SetNorm, "Sets a specific norm to <me> Returns True if done, False if <norm> is not available", py::arg("norm"));
cls_XSControl_Reader.def("SetWS", [](XSControl_Reader &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.SetWS(a0); });
cls_XSControl_Reader.def("SetWS", (void (XSControl_Reader::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &XSControl_Reader::SetWS, "Sets a specific session to <me>", py::arg("WS"), py::arg("scratch"));
cls_XSControl_Reader.def("WS", (opencascade::handle<XSControl_WorkSession> (XSControl_Reader::*)() const) &XSControl_Reader::WS, "Returns the session used in <me>");
cls_XSControl_Reader.def("ReadFile", (IFSelect_ReturnStatus (XSControl_Reader::*)(const Standard_CString)) &XSControl_Reader::ReadFile, "Loads a file and returns the read status Zero for a Model which compies with the Controller", py::arg("filename"));
cls_XSControl_Reader.def("Model", (opencascade::handle<Interface_InterfaceModel> (XSControl_Reader::*)() const) &XSControl_Reader::Model, "Returns the model. It can then be consulted (header, product)");
cls_XSControl_Reader.def("GiveList", [](XSControl_Reader &self) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.GiveList(); });
cls_XSControl_Reader.def("GiveList", [](XSControl_Reader &self, const Standard_CString a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.GiveList(a0); });
cls_XSControl_Reader.def("GiveList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_Reader::*)(const Standard_CString, const Standard_CString)) &XSControl_Reader::GiveList, "Returns a list of entities from the IGES or STEP file according to the following rules: - if first and second are empty strings, the whole file is selected. - if first is an entity number or label, the entity referred to is selected. - if first is a list of entity numbers/labels separated by commas, the entities referred to are selected, - if first is the name of a selection in the worksession and second is not defined, the list contains the standard output for that selection. - if first is the name of a selection and second is defined, the criterion defined by second is applied to the result of the first selection. A selection is an operator which computes a list of entities from a list given in input according to its type. If no list is specified, the selection computes its list of entities from the whole model. A selection can be: - A predefined selection (xst-transferrable-mode) - A filter based on a signature A Signature is an operator which returns a string from an entity according to its type. For example: - 'xst-type' (CDL) - 'iges-level' - 'step-type'. For example, if you wanted to select only the advanced_faces in a STEP file you would use the following code: Example Reader.GiveList('xst-transferrable-roots','step-type(ADVANCED_FACE)'); Warning If the value given to second is incorrect, it will simply be ignored.", py::arg("first"), py::arg("second"));
cls_XSControl_Reader.def("GiveList", (opencascade::handle<TColStd_HSequenceOfTransient> (XSControl_Reader::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &XSControl_Reader::GiveList, "Computes a List of entities from the model as follows <first> beeing a Selection, <ent> beeing an entity or a list of entities (as a HSequenceOfTransient) : the standard result of this selection applied to this list if <first> is erroneous, a null handle is returned", py::arg("first"), py::arg("ent"));
cls_XSControl_Reader.def("NbRootsForTransfer", (Standard_Integer (XSControl_Reader::*)()) &XSControl_Reader::NbRootsForTransfer, "Determines the list of root entities which are candidate for a transfer to a Shape, and returns the number of entities in the list");
cls_XSControl_Reader.def("RootForTransfer", [](XSControl_Reader &self) -> opencascade::handle<Standard_Transient> { return self.RootForTransfer(); });
cls_XSControl_Reader.def("RootForTransfer", (opencascade::handle<Standard_Transient> (XSControl_Reader::*)(const Standard_Integer)) &XSControl_Reader::RootForTransfer, "Returns an IGES or STEP root entity for translation. The entity is identified by its rank in a list.", py::arg("num"));
cls_XSControl_Reader.def("TransferOneRoot", [](XSControl_Reader &self) -> Standard_Boolean { return self.TransferOneRoot(); });
cls_XSControl_Reader.def("TransferOneRoot", (Standard_Boolean (XSControl_Reader::*)(const Standard_Integer)) &XSControl_Reader::TransferOneRoot, "Translates a root identified by the rank num in the model. false is returned if no shape is produced.", py::arg("num"));
cls_XSControl_Reader.def("TransferOne", (Standard_Boolean (XSControl_Reader::*)(const Standard_Integer)) &XSControl_Reader::TransferOne, "Translates an IGES or STEP entity identified by the rank num in the model. false is returned if no shape is produced.", py::arg("num"));
cls_XSControl_Reader.def("TransferEntity", (Standard_Boolean (XSControl_Reader::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_Reader::TransferEntity, "Translates an IGES or STEP entity in the model. true is returned if a shape is produced; otherwise, false is returned.", py::arg("start"));
cls_XSControl_Reader.def("TransferList", (Standard_Integer (XSControl_Reader::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &XSControl_Reader::TransferList, "Translates a list of entities. Returns the number of IGES or STEP entities that were successfully translated. The list can be produced with GiveList. Warning - This function does not clear the existing output shapes.", py::arg("list"));
cls_XSControl_Reader.def("TransferRoots", (Standard_Integer (XSControl_Reader::*)()) &XSControl_Reader::TransferRoots, "Translates all translatable roots and returns the number of successful translations. Warning - This function clears existing output shapes first.");
cls_XSControl_Reader.def("ClearShapes", (void (XSControl_Reader::*)()) &XSControl_Reader::ClearShapes, "Clears the list of shapes that may have accumulated in calls to TransferOne or TransferRoot.C");
cls_XSControl_Reader.def("NbShapes", (Standard_Integer (XSControl_Reader::*)() const) &XSControl_Reader::NbShapes, "Returns the number of shapes produced by translation.");
cls_XSControl_Reader.def("Shape", [](XSControl_Reader &self) -> TopoDS_Shape { return self.Shape(); });
cls_XSControl_Reader.def("Shape", (TopoDS_Shape (XSControl_Reader::*)(const Standard_Integer) const) &XSControl_Reader::Shape, "Returns the shape resulting from a translation and identified by the rank num. num equals 1 by default. In other words, the first shape resulting from the translation is returned.", py::arg("num"));
cls_XSControl_Reader.def("OneShape", (TopoDS_Shape (XSControl_Reader::*)() const) &XSControl_Reader::OneShape, "Returns all of the results in a single shape which is: - a null shape if there are no results, - a shape if there is one result, - a compound containing the resulting shapes if there are more than one.");
cls_XSControl_Reader.def("PrintCheckLoad", (void (XSControl_Reader::*)(const Standard_Boolean, const IFSelect_PrintCount) const) &XSControl_Reader::PrintCheckLoad, "Prints the check list attached to loaded data, on the Standard Trace File (starts at cout) All messages or fails only, according to <failsonly> mode = 0 : per entity, prints messages mode = 1 : per message, just gives count of entities per check mode = 2 : also gives entity numbers", py::arg("failsonly"), py::arg("mode"));
cls_XSControl_Reader.def("PrintCheckTransfer", (void (XSControl_Reader::*)(const Standard_Boolean, const IFSelect_PrintCount) const) &XSControl_Reader::PrintCheckTransfer, "Displays check results for the last translation of IGES or STEP entities to Open CASCADE entities. Only fail messages are displayed if failsonly is true. All messages are displayed if failsonly is false. mode determines the contents and the order of the messages according to the terms of the IFSelect_PrintCount enumeration.", py::arg("failsonly"), py::arg("mode"));
cls_XSControl_Reader.def("PrintStatsTransfer", [](XSControl_Reader &self, const Standard_Integer a0) -> void { return self.PrintStatsTransfer(a0); });
cls_XSControl_Reader.def("PrintStatsTransfer", (void (XSControl_Reader::*)(const Standard_Integer, const Standard_Integer) const) &XSControl_Reader::PrintStatsTransfer, "Displays the statistics for the last translation. what defines the kind of statistics that are displayed as follows: - 0 gives general statistics (number of translated roots, number of warnings, number of fail messages), - 1 gives root results, - 2 gives statistics for all checked entities, - 3 gives the list of translated entities, - 4 gives warning and fail messages, - 5 gives fail messages only. The use of mode depends on the value of what. If what is 0, mode is ignored. If what is 1, 2 or 3, mode defines the following: - 0 lists the numbers of IGES or STEP entities in the respective model - 1 gives the number, identifier, type and result type for each IGES or STEP entity and/or its status (fail, warning, etc.) - 2 gives maximum information for each IGES or STEP entity (i.e. checks) - 3 gives the number of entities per type of IGES or STEP entity - 4 gives the number of IGES or STEP entities per result type and/or status - 5 gives the number of pairs (IGES or STEP or result type and status) - 6 gives the number of pairs (IGES or STEP or result type and status) AND the list of entity numbers in the IGES or STEP model. If what is 4 or 5, mode defines the warning and fail messages as follows: - if mode is 0 all warnings and checks per entity are returned - if mode is 2 the list of entities per warning is returned. If mode is not set, only the list of all entities per warning is given.", py::arg("what"), py::arg("mode"));
cls_XSControl_Reader.def("GetStatsTransfer", [](XSControl_Reader &self, const opencascade::handle<TColStd_HSequenceOfTransient> & list, Standard_Integer & nbMapped, Standard_Integer & nbWithResult, Standard_Integer & nbWithFail){ self.GetStatsTransfer(list, nbMapped, nbWithResult, nbWithFail); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(nbMapped, nbWithResult, nbWithFail); }, "Gives statistics about Transfer", py::arg("list"), py::arg("nbMapped"), py::arg("nbWithResult"), py::arg("nbWithFail"));

// Enums

}