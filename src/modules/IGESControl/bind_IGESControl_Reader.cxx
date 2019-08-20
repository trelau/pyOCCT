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
#include <IGESData_IGESModel.hxx>
#include <IFSelect_PrintFail.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IGESControl_Reader.hxx>

void bind_IGESControl_Reader(py::module &mod){

py::class_<IGESControl_Reader, std::unique_ptr<IGESControl_Reader>, XSControl_Reader> cls_IGESControl_Reader(mod, "IGESControl_Reader", "Reads IGES files, checks them and translates their contents into Open CASCADE models. The IGES data can be that of a whole model or that of a specific list of entities in the model. As in XSControl_Reader, you specify the list using a selection. For translation of iges files it is possible to use the following sequence: To change parameters of translation class Interface_Static should be used before the beginning of translation (see IGES Parameters and General Parameters) Creation of reader IGESControl_Reader reader; To load a file in a model use method: reader.ReadFile('filename.igs') To check a loading file use method Check: reader.Check(failsonly); where failsonly is equal to Standard_True or Standard_False; To print the results of load: reader.PrintCheckLoad(failsonly,mode) where mode is equal to the value of enumeration IFSelect_PrintCount To transfer entities from a model the following methods can be used: for the whole model reader.TransferRoots(onlyvisible); where onlyvisible is equal to Standard_True or Standard_False; To transfer a list of entities: reader.TransferList(list); To transfer one entity reader.TransferEntity(ent) or reader.Transfer(num); To obtain a result the following method can be used: reader.IsDone() reader.NbShapes() and reader.Shape(num); or reader.OneShape(); To print the results of transfer use method: reader.PrintTransferInfo(failwarn,mode); where printfail is equal to the value of enumeration IFSelect_PrintFail, mode see above. Gets correspondence between an IGES entity and a result shape obtained therefrom. reader.TransientProcess(); TopoDS_Shape shape = TransferBRep::ShapeResult(reader.TransientProcess(),ent);");

// Constructors
cls_IGESControl_Reader.def(py::init<>());
cls_IGESControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_IGESControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_IGESControl_Reader.def_static("operator new_", (void * (*)(size_t)) &IGESControl_Reader::operator new, "None", py::arg("theSize"));
// cls_IGESControl_Reader.def_static("operator delete_", (void (*)(void *)) &IGESControl_Reader::operator delete, "None", py::arg("theAddress"));
// cls_IGESControl_Reader.def_static("operator new[]_", (void * (*)(size_t)) &IGESControl_Reader::operator new[], "None", py::arg("theSize"));
// cls_IGESControl_Reader.def_static("operator delete[]_", (void (*)(void *)) &IGESControl_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_IGESControl_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &IGESControl_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESControl_Reader.def_static("operator delete_", (void (*)(void *, void *)) &IGESControl_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESControl_Reader.def("SetReadVisible", (void (IGESControl_Reader::*)(const Standard_Boolean)) &IGESControl_Reader::SetReadVisible, "Set the transion of ALL Roots (if theReadOnlyVisible is False) or of Visible Roots (if theReadOnlyVisible is True)", py::arg("ReadRoot"));
cls_IGESControl_Reader.def("GetReadVisible", (Standard_Boolean (IGESControl_Reader::*)() const) &IGESControl_Reader::GetReadVisible, "None");
cls_IGESControl_Reader.def("IGESModel", (opencascade::handle<IGESData_IGESModel> (IGESControl_Reader::*)() const) &IGESControl_Reader::IGESModel, "Returns the model as a IGESModel. It can then be consulted (header, product)");
cls_IGESControl_Reader.def("NbRootsForTransfer", (Standard_Integer (IGESControl_Reader::*)()) &IGESControl_Reader::NbRootsForTransfer, "Determines the list of root entities from Model which are candidate for a transfer to a Shape (type of entities is PRODUCT) <theReadOnlyVisible> is taken into account to define roots");
cls_IGESControl_Reader.def("PrintTransferInfo", (void (IGESControl_Reader::*)(const IFSelect_PrintFail, const IFSelect_PrintCount) const) &IGESControl_Reader::PrintTransferInfo, "Prints Statistics and check list for Transfer", py::arg("failwarn"), py::arg("mode"));

// Enums

}