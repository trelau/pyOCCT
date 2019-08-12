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
#include <XSControl_Reader.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_StepModel.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <STEPControl_Reader.hxx>

void bind_STEPControl_Reader(py::module &mod){

py::class_<STEPControl_Reader, std::unique_ptr<STEPControl_Reader, Deleter<STEPControl_Reader>>, XSControl_Reader> cls_STEPControl_Reader(mod, "STEPControl_Reader", "Reads STEP files, checks them and translates their contents into Open CASCADE models. The STEP data can be that of a whole model or that of a specific list of entities in the model. As in XSControl_Reader, you specify the list using a selection. For the translation of iges files it is possible to use next sequence: To change translation parameters class Interface_Static should be used before beginning of translation (see STEP Parameters and General Parameters) Creation of reader - STEPControl_Reader reader; To load s file in a model use method reader.ReadFile('filename.stp') To print load results reader.PrintCheckLoad(failsonly,mode) where mode is equal to the value of enumeration IFSelect_PrintCount For definition number of candidates : Standard_Integer nbroots = reader. NbRootsForTransfer(); To transfer entities from a model the following methods can be used: for the whole model - reader.TransferRoots(); to transfer a list of entities: reader.TransferList(list); to transfer one entity Handle(Standard_Transient) ent = reader.RootForTransfer(num); reader.TransferEntity(ent), or reader.TransferOneRoot(num), or reader.TransferOne(num), or reader.TransferRoot(num) To obtain the result the following method can be used: reader.NbShapes() and reader.Shape(num); or reader.OneShape(); To print the results of transfer use method: reader.PrintCheckTransfer(failwarn,mode); where printfail is equal to the value of enumeration IFSelect_PrintFail, mode see above; or reader.PrintStatsTransfer(); Gets correspondence between a STEP entity and a result shape obtained from it. Handle(XSControl_WorkSession) WS = reader.WS(); if ( WS->TransferReader()->HasResult(ent) ) TopoDS_Shape shape = WS->TransferReader()->ShapeResult(ent);");

// Constructors
cls_STEPControl_Reader.def(py::init<>());
cls_STEPControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_STEPControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_STEPControl_Reader.def_static("operator new_", (void * (*)(size_t)) &STEPControl_Reader::operator new, "None", py::arg("theSize"));
// cls_STEPControl_Reader.def_static("operator delete_", (void (*)(void *)) &STEPControl_Reader::operator delete, "None", py::arg("theAddress"));
// cls_STEPControl_Reader.def_static("operator new[]_", (void * (*)(size_t)) &STEPControl_Reader::operator new[], "None", py::arg("theSize"));
// cls_STEPControl_Reader.def_static("operator delete[]_", (void (*)(void *)) &STEPControl_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_STEPControl_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &STEPControl_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPControl_Reader.def_static("operator delete_", (void (*)(void *, void *)) &STEPControl_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPControl_Reader.def("StepModel", (opencascade::handle<StepData_StepModel> (STEPControl_Reader::*)() const) &STEPControl_Reader::StepModel, "Returns the model as a StepModel. It can then be consulted (header, product)");
cls_STEPControl_Reader.def("TransferRoot", [](STEPControl_Reader &self) -> Standard_Boolean { return self.TransferRoot(); });
cls_STEPControl_Reader.def("TransferRoot", (Standard_Boolean (STEPControl_Reader::*)(const Standard_Integer)) &STEPControl_Reader::TransferRoot, "Transfers a root given its rank in the list of candidate roots Default is the first one Returns True if a shape has resulted, false else Same as inherited TransferOneRoot, kept for compatibility", py::arg("num"));
cls_STEPControl_Reader.def("NbRootsForTransfer", (Standard_Integer (STEPControl_Reader::*)()) &STEPControl_Reader::NbRootsForTransfer, "Determines the list of root entities from Model which are candidate for a transfer to a Shape (type of entities is PRODUCT)");
cls_STEPControl_Reader.def("FileUnits", (void (STEPControl_Reader::*)(TColStd_SequenceOfAsciiString &, TColStd_SequenceOfAsciiString &, TColStd_SequenceOfAsciiString &)) &STEPControl_Reader::FileUnits, "Returns sequence of all unit names for shape representations found in file", py::arg("theUnitLengthNames"), py::arg("theUnitAngleNames"), py::arg("theUnitSolidAngleNames"));

// Enums

}