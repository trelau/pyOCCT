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
#include <BRepTools_Modification.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <Draft_ErrorStatus.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Draft_Modification.hxx>
#include <Standard_Type.hxx>
#include <TopAbs_Orientation.hxx>
#include <Draft_IndexedDataMapOfFaceFaceInfo.hxx>
#include <Draft_IndexedDataMapOfEdgeEdgeInfo.hxx>
#include <Draft_IndexedDataMapOfVertexVertexInfo.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>

void bind_Draft_Modification(py::module &mod){

py::class_<Draft_Modification, opencascade::handle<Draft_Modification>, BRepTools_Modification> cls_Draft_Modification(mod, "Draft_Modification", "None");

// Constructors
cls_Draft_Modification.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
cls_Draft_Modification.def("Clear", (void (Draft_Modification::*)()) &Draft_Modification::Clear, "Resets on the same shape.");
cls_Draft_Modification.def("Init", (void (Draft_Modification::*)(const TopoDS_Shape &)) &Draft_Modification::Init, "Changes the basis shape and resets.", py::arg("S"));
cls_Draft_Modification.def("Add", [](Draft_Modification &self, const TopoDS_Face & a0, const gp_Dir & a1, const Standard_Real a2, const gp_Pln & a3) -> Standard_Boolean { return self.Add(a0, a1, a2, a3); });
cls_Draft_Modification.def("Add", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Face &, const gp_Dir &, const Standard_Real, const gp_Pln &, const Standard_Boolean)) &Draft_Modification::Add, "Adds the face F and propagates the draft modification to its neighbour faces if they are tangent. If an error occurs, will return False and ProblematicShape will return the 'bad' face.", py::arg("F"), py::arg("Direction"), py::arg("Angle"), py::arg("NeutralPlane"), py::arg("Flag"));
cls_Draft_Modification.def("Remove", (void (Draft_Modification::*)(const TopoDS_Face &)) &Draft_Modification::Remove, "Removes the face F and the neighbour faces if they are tangent. It will be necessary to call this method if the method Add returns Standard_False, to unset ProblematicFace.", py::arg("F"));
cls_Draft_Modification.def("Perform", (void (Draft_Modification::*)()) &Draft_Modification::Perform, "Performs the draft angle modification and sets the value returned by the method IsDone. If an error occurs, IsDone will return Standard_False, and an error status will be given by the method Error, and the shape on which the problem appeared will be given by ProblematicShape");
cls_Draft_Modification.def("IsDone", (Standard_Boolean (Draft_Modification::*)() const) &Draft_Modification::IsDone, "Returns True if Perform has been succesfully called. Otherwise more information can be obtained using the methods Error() and ProblematicShape().");
cls_Draft_Modification.def("Error", (Draft_ErrorStatus (Draft_Modification::*)() const) &Draft_Modification::Error, "None");
cls_Draft_Modification.def("ProblematicShape", (const TopoDS_Shape & (Draft_Modification::*)() const) &Draft_Modification::ProblematicShape, "Returns the shape (Face, Edge or Vertex) on which an error occured.");
cls_Draft_Modification.def("ConnectedFaces", (const TopTools_ListOfShape & (Draft_Modification::*)(const TopoDS_Face &)) &Draft_Modification::ConnectedFaces, "Returns all the faces which have been added together with the face <F>.", py::arg("F"));
cls_Draft_Modification.def("ModifiedFaces", (const TopTools_ListOfShape & (Draft_Modification::*)()) &Draft_Modification::ModifiedFaces, "Returns all the faces on which a modification has been given.");
cls_Draft_Modification.def("NewSurface", [](Draft_Modification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. Here it will be set to Standard_False.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_Draft_Modification.def("NewCurve", [](Draft_Modification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_Draft_Modification.def("NewPoint", [](Draft_Modification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_Draft_Modification.def("NewCurve2d", [](Draft_Modification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_Draft_Modification.def("NewParameter", [](Draft_Modification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_Draft_Modification.def("Continuity", (GeomAbs_Shape (Draft_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &Draft_Modification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_Draft_Modification.def_static("get_type_name_", (const char * (*)()) &Draft_Modification::get_type_name, "None");
cls_Draft_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Draft_Modification::get_type_descriptor, "None");
cls_Draft_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (Draft_Modification::*)() const) &Draft_Modification::DynamicType, "None");

// Enums

}