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
#include <BRepToIGES_BREntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <BRepToIGES_BRSolid.hxx>

void bind_BRepToIGES_BRSolid(py::module &mod){

py::class_<BRepToIGES_BRSolid, BRepToIGES_BREntity> cls_BRepToIGES_BRSolid(mod, "BRepToIGES_BRSolid", "This class implements the transfer of Shape Entities from Geom To IGES. These can be : . Vertex . Edge . Wire");

// Constructors
cls_BRepToIGES_BRSolid.def(py::init<>());
cls_BRepToIGES_BRSolid.def(py::init<const BRepToIGES_BREntity &>(), py::arg("BR"));

// Fields

// Methods
// cls_BRepToIGES_BRSolid.def_static("operator new_", (void * (*)(size_t)) &BRepToIGES_BRSolid::operator new, "None", py::arg("theSize"));
// cls_BRepToIGES_BRSolid.def_static("operator delete_", (void (*)(void *)) &BRepToIGES_BRSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepToIGES_BRSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepToIGES_BRSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepToIGES_BRSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepToIGES_BRSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepToIGES_BRSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepToIGES_BRSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepToIGES_BRSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepToIGES_BRSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepToIGES_BRSolid.def("TransferSolid", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRSolid::*)(const TopoDS_Shape &)) &BRepToIGES_BRSolid::TransferSolid, "Transfert a Shape entity from TopoDS to IGES this entity must be a Solid or a CompSolid or a Compound. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGES_BRSolid.def("TransferSolid", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRSolid::*)(const TopoDS_Solid &)) &BRepToIGES_BRSolid::TransferSolid, "Transfert a Solid entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGES_BRSolid.def("TransferCompSolid", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRSolid::*)(const TopoDS_CompSolid &)) &BRepToIGES_BRSolid::TransferCompSolid, "Transfert an CompSolid entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGES_BRSolid.def("TransferCompound", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRSolid::*)(const TopoDS_Compound &)) &BRepToIGES_BRSolid::TransferCompound, "Transfert a Compound entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

// Enums

}