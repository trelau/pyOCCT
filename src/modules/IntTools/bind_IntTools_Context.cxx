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
#include <NCollection_BaseAllocator.hxx>
#include <IntTools_FClass2d.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <IntTools_SurfaceRangeLocalizeData.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <TopoDS_Solid.hxx>
#include <Geom2dHatch_Hatcher.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Bnd_OBB.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <IntTools_Curve.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_Context.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TColStd_MapTransientHasher.hxx>

void bind_IntTools_Context(py::module &mod){

py::class_<IntTools_Context, opencascade::handle<IntTools_Context>, Standard_Transient> cls_IntTools_Context(mod, "IntTools_Context", "The intersection Context contains geometrical and topological toolkit (classifiers, projectors, etc). The intersection Context is for caching the tools to increase the performance.");

// Constructors
cls_IntTools_Context.def(py::init<>());
cls_IntTools_Context.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_IntTools_Context.def("FClass2d", (IntTools_FClass2d & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::FClass2d, "Returns a reference to point classifier for given face", py::arg("aF"));
cls_IntTools_Context.def("ProjPS", (GeomAPI_ProjectPointOnSurf & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::ProjPS, "Returns a reference to point projector for given face", py::arg("aF"));
cls_IntTools_Context.def("ProjPC", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const TopoDS_Edge &)) &IntTools_Context::ProjPC, "Returns a reference to point projector for given edge", py::arg("aE"));
cls_IntTools_Context.def("ProjPT", (GeomAPI_ProjectPointOnCurve & (IntTools_Context::*)(const opencascade::handle<Geom_Curve> &)) &IntTools_Context::ProjPT, "Returns a reference to point projector for given curve", py::arg("aC"));
cls_IntTools_Context.def("SurfaceData", (IntTools_SurfaceRangeLocalizeData & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceData, "Returns a reference to surface localization data for given face", py::arg("aF"));
cls_IntTools_Context.def("SolidClassifier", (BRepClass3d_SolidClassifier & (IntTools_Context::*)(const TopoDS_Solid &)) &IntTools_Context::SolidClassifier, "Returns a reference to solid classifier for given solid", py::arg("aSolid"));
cls_IntTools_Context.def("Hatcher", (Geom2dHatch_Hatcher & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::Hatcher, "Returns a reference to 2D hatcher for given face", py::arg("aF"));
cls_IntTools_Context.def("SurfaceAdaptor", (BRepAdaptor_Surface & (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::SurfaceAdaptor, "Returns a reference to surface adaptor for given face", py::arg("theFace"));
cls_IntTools_Context.def("OBB", [](IntTools_Context &self, const TopoDS_Shape & a0) -> Bnd_OBB & { return self.OBB(a0); });
cls_IntTools_Context.def("OBB", (Bnd_OBB & (IntTools_Context::*)(const TopoDS_Shape &, const Standard_Real)) &IntTools_Context::OBB, "Builds and stores an Oriented Bounding Box for the shape. Returns a reference to OBB.", py::arg("theShape"), py::arg("theFuzzyValue"));
cls_IntTools_Context.def("UVBounds", [](IntTools_Context &self, const TopoDS_Face & theFace, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ self.UVBounds(theFace, UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "Computes the boundaries of the face using surface adaptor", py::arg("theFace"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_IntTools_Context.def("ComputePE", [](IntTools_Context &self, const gp_Pnt & theP, const Standard_Real theTolP, const TopoDS_Edge & theE, Standard_Real & theT, Standard_Real & theDist){ Standard_Integer rv = self.ComputePE(theP, theTolP, theE, theT, theDist); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &>(rv, theT, theDist); }, "Computes parameter of the Point theP on the edge aE. Returns zero if the distance between point and edge is less than sum of tolerance value of edge and theTopP, otherwise and for following conditions returns negative value 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theP"), py::arg("theTolP"), py::arg("theE"), py::arg("theT"), py::arg("theDist"));
cls_IntTools_Context.def("ComputeVE", [](IntTools_Context &self, const TopoDS_Vertex & theV, const TopoDS_Edge & theE, Standard_Real & theT, Standard_Real & theTol, const Standard_Real theFuzz){ Standard_Integer rv = self.ComputeVE(theV, theE, theT, theTol, theFuzz); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &>(rv, theT, theTol); }, "Computes parameter of the vertex aV on the edge aE and correct tolerance value for the vertex on the edge. Returns zero if the distance between vertex and edge is less than sum of tolerances and the fuzzy value, otherwise and for following conditions returns negative value: 1. the edge is degenerated (-1) 2. the edge does not contain 3d curve and pcurves (-2) 3. projection algorithm failed (-3)", py::arg("theV"), py::arg("theE"), py::arg("theT"), py::arg("theTol"), py::arg("theFuzz"));
cls_IntTools_Context.def("ComputeVF", [](IntTools_Context &self, const TopoDS_Vertex & theVertex, const TopoDS_Face & theFace, Standard_Real & theU, Standard_Real & theV, Standard_Real & theTol, const Standard_Real theFuzz){ Standard_Integer rv = self.ComputeVF(theVertex, theFace, theU, theV, theTol, theFuzz); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, theU, theV, theTol); }, "Computes UV parameters of the vertex aV on face aF and correct tolerance value for the vertex on the face. Returns zero if the distance between vertex and face is less than or equal the sum of tolerances and the fuzzy value and the projection point lays inside boundaries of the face. For following conditions returns negative value 1. projection algorithm failed (-1) 2. distance is more than sum of tolerances (-2) 3. projection point out or on the boundaries of face (-3)", py::arg("theVertex"), py::arg("theFace"), py::arg("theU"), py::arg("theV"), py::arg("theTol"), py::arg("theFuzz"));
cls_IntTools_Context.def("StatePointFace", (TopAbs_State (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::StatePointFace, "Returns the state of the point aP2D relative to face aF", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsPointInFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsPointInFace, "Returns true if the point aP2D is inside the boundaries of the face aF, otherwise returns false", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsPointInOnFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &, const gp_Pnt2d &)) &IntTools_Context::IsPointInOnFace, "Returns true if the point aP2D is inside or on the boundaries of aF", py::arg("aF"), py::arg("aP2D"));
cls_IntTools_Context.def("IsValidPointForFace", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFace, "Returns true if the distance between point aP3D and face aF is less or equal to tolerance aTol and projection point is inside or on the boundaries of the face aF", py::arg("aP3D"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidPointForFaces", (Standard_Boolean (IntTools_Context::*)(const gp_Pnt &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidPointForFaces, "Returns true if IsValidPointForFace returns true for both face aF1 and aF2", py::arg("aP3D"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidBlockForFace", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFace, "Returns true if IsValidPointForFace returns true for some 3d point that lay on the curve aIC bounded by parameters aT1 and aT2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF"), py::arg("aTol"));
cls_IntTools_Context.def("IsValidBlockForFaces", (Standard_Boolean (IntTools_Context::*)(const Standard_Real, const Standard_Real, const IntTools_Curve &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real)) &IntTools_Context::IsValidBlockForFaces, "Returns true if IsValidBlockForFace returns true for both faces aF1 and aF2", py::arg("aT1"), py::arg("aT2"), py::arg("aIC"), py::arg("aF1"), py::arg("aF2"), py::arg("aTol"));
cls_IntTools_Context.def("IsVertexOnLine", [](IntTools_Context &self, const TopoDS_Vertex & aV, const IntTools_Curve & aIC, const Standard_Real aTolC, Standard_Real & aT){ Standard_Boolean rv = self.IsVertexOnLine(aV, aIC, aTolC, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
cls_IntTools_Context.def("IsVertexOnLine", [](IntTools_Context &self, const TopoDS_Vertex & aV, const Standard_Real aTolV, const IntTools_Curve & aIC, const Standard_Real aTolC, Standard_Real & aT){ Standard_Boolean rv = self.IsVertexOnLine(aV, aTolV, aIC, aTolC, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the vertex aV on the curve aIC. Returns true if the distance between vertex and curve is less than sum of tolerance of aV and aTolC, otherwise or if projection algorithm failed returns false (in this case aT isn't significant)", py::arg("aV"), py::arg("aTolV"), py::arg("aIC"), py::arg("aTolC"), py::arg("aT"));
cls_IntTools_Context.def("ProjectPointOnEdge", [](IntTools_Context &self, const gp_Pnt & aP, const TopoDS_Edge & aE, Standard_Real & aT){ Standard_Boolean rv = self.ProjectPointOnEdge(aP, aE, aT); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aT); }, "Computes parameter of the point aP on the edge aE. Returns false if projection algorithm failed other wiese returns true.", py::arg("aP"), py::arg("aE"), py::arg("aT"));
cls_IntTools_Context.def("BndBox", (Bnd_Box & (IntTools_Context::*)(const TopoDS_Shape &)) &IntTools_Context::BndBox, "None", py::arg("theS"));
cls_IntTools_Context.def("IsInfiniteFace", (Standard_Boolean (IntTools_Context::*)(const TopoDS_Face &)) &IntTools_Context::IsInfiniteFace, "Returns true if the solid <theFace> has infinite bounds", py::arg("theFace"));
cls_IntTools_Context.def("SetPOnSProjectionTolerance", (void (IntTools_Context::*)(const Standard_Real)) &IntTools_Context::SetPOnSProjectionTolerance, "Sets tolerance to be used for projection of point on surface. Clears map of already cached projectors in order to maintain correct value for all projectors", py::arg("theValue"));
cls_IntTools_Context.def_static("get_type_name_", (const char * (*)()) &IntTools_Context::get_type_name, "None");
cls_IntTools_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntTools_Context::get_type_descriptor, "None");
cls_IntTools_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_Context::*)() const) &IntTools_Context::DynamicType, "None");

// Enums

}