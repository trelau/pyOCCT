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
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepToIGES_BRWire.hxx>

void bind_BRepToIGES_BRWire(py::module &mod){

py::class_<BRepToIGES_BRWire, std::unique_ptr<BRepToIGES_BRWire, Deleter<BRepToIGES_BRWire>>, BRepToIGES_BREntity> cls_BRepToIGES_BRWire(mod, "BRepToIGES_BRWire", "This class implements the transfer of Shape Entities from Geom To IGES. These can be : . Vertex . Edge . Wire");

// Constructors
cls_BRepToIGES_BRWire.def(py::init<>());
cls_BRepToIGES_BRWire.def(py::init<const BRepToIGES_BREntity &>(), py::arg("BR"));

// Fields

// Methods
// cls_BRepToIGES_BRWire.def_static("operator new_", (void * (*)(size_t)) &BRepToIGES_BRWire::operator new, "None", py::arg("theSize"));
// cls_BRepToIGES_BRWire.def_static("operator delete_", (void (*)(void *)) &BRepToIGES_BRWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepToIGES_BRWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepToIGES_BRWire::operator new[], "None", py::arg("theSize"));
// cls_BRepToIGES_BRWire.def_static("operator delete[]_", (void (*)(void *)) &BRepToIGES_BRWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepToIGES_BRWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepToIGES_BRWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepToIGES_BRWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepToIGES_BRWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepToIGES_BRWire.def("TransferWire", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Shape &)) &BRepToIGES_BRWire::TransferWire, "Transfert a Shape entity from TopoDS to IGES this entity must be a Vertex or an Edge or a Wire. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_BRepToIGES_BRWire.def("TransferVertex", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Vertex &)) &BRepToIGES_BRWire::TransferVertex, "Transfert a Vertex entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("myvertex"));
cls_BRepToIGES_BRWire.def("TransferVertex", [](BRepToIGES_BRWire &self, const TopoDS_Vertex & myvertex, const TopoDS_Edge & myedge, Standard_Real & parameter){ opencascade::handle<IGESData_IGESEntity> rv = self.TransferVertex(myvertex, myedge, parameter); return std::tuple<opencascade::handle<IGESData_IGESEntity>, Standard_Real &>(rv, parameter); }, "Transfert a Vertex entity on an Edge from TopoDS to IGES Returns the parameter of myvertex on myedge. If this Entity could not be converted, this member returns a NullEntity.", py::arg("myvertex"), py::arg("myedge"), py::arg("parameter"));
cls_BRepToIGES_BRWire.def("TransferVertex", [](BRepToIGES_BRWire &self, const TopoDS_Vertex & myvertex, const TopoDS_Edge & myedge, const TopoDS_Face & myface, Standard_Real & parameter){ opencascade::handle<IGESData_IGESEntity> rv = self.TransferVertex(myvertex, myedge, myface, parameter); return std::tuple<opencascade::handle<IGESData_IGESEntity>, Standard_Real &>(rv, parameter); }, "Transfert a Vertex entity of an edge on a Face from TopoDS to IGES Returns the parameter of myvertex on the pcurve of myedge on myface If this Entity could not be converted, this member returns a NullEntity.", py::arg("myvertex"), py::arg("myedge"), py::arg("myface"), py::arg("parameter"));
cls_BRepToIGES_BRWire.def("TransferVertex", [](BRepToIGES_BRWire &self, const TopoDS_Vertex & myvertex, const TopoDS_Edge & myedge, const opencascade::handle<Geom_Surface> & mysurface, const TopLoc_Location & myloc, Standard_Real & parameter){ opencascade::handle<IGESData_IGESEntity> rv = self.TransferVertex(myvertex, myedge, mysurface, myloc, parameter); return std::tuple<opencascade::handle<IGESData_IGESEntity>, Standard_Real &>(rv, parameter); }, "Transfert a Vertex entity of an edge on a Surface from TopoDS to IGES Returns the parameter of myvertex on the pcurve of myedge on mysurface If this Entity could not be converted, this member returns a NullEntity.", py::arg("myvertex"), py::arg("myedge"), py::arg("mysurface"), py::arg("myloc"), py::arg("parameter"));
cls_BRepToIGES_BRWire.def("TransferVertex", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Vertex &, const TopoDS_Face &, gp_Pnt2d &)) &BRepToIGES_BRWire::TransferVertex, "Transfert a Vertex entity on a Face from TopoDS to IGES Returns the parameters of myvertex on myface If this Entity could not be converted, this member returns a NullEntity.", py::arg("myvertex"), py::arg("myface"), py::arg("mypoint"));
cls_BRepToIGES_BRWire.def("TransferEdge", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Edge &, const Standard_Boolean)) &BRepToIGES_BRWire::TransferEdge, "Transfert an Edge entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity. isBRepMode indicates if write mode is BRep (True when called from BRepToIGESBRep and False when from BRepToIGES) If edge is REVERSED and isBRepMode is False 3D edge curve is reversed, otherwise, not.", py::arg("myedge"), py::arg("isBRepMode"));
cls_BRepToIGES_BRWire.def("TransferEdge", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Boolean)) &BRepToIGES_BRWire::TransferEdge, "Transfert an Edge entity on a Face from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity. isBRepMode indicates if write mode is BRep (True when called from BRepToIGESBRep and False when from BRepToIGES) passing into Transform2dCurve()", py::arg("myedge"), py::arg("myface"), py::arg("length"), py::arg("isBRepMode"));
cls_BRepToIGES_BRWire.def("TransferWire", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Wire &)) &BRepToIGES_BRWire::TransferWire, "Transfert a Wire entity from TopoDS to IGES If this Entity could not be converted, this member returns a NullEntity.", py::arg("mywire"));
cls_BRepToIGES_BRWire.def("TransferWire", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BRWire::*)(const TopoDS_Wire &, const TopoDS_Face &, opencascade::handle<IGESData_IGESEntity> &, const Standard_Real)) &BRepToIGES_BRWire::TransferWire, "Transfert a Wire entity from TopoDS to IGES. Returns the curve associated to mywire in the parametric space of myface. If this Entity could not be converted, this member returns a NullEntity. Parameter IsRevol is not used anymore", py::arg("mywire"), py::arg("myface"), py::arg("mycurve2d"), py::arg("length"));

// Enums

}