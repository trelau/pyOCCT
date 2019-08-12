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

void bind_ShapeAnalysis(py::module &);
void bind_ShapeAnalysis_BoxBndTree(py::module &);
void bind_ShapeAnalysis_BoxBndTreeSelector(py::module &);
void bind_ShapeAnalysis_DataMapOfShapeListOfReal(py::module &);
void bind_ShapeAnalysis_DataMapIteratorOfDataMapOfShapeListOfReal(py::module &);
void bind_ShapeAnalysis_CheckSmallFace(py::module &);
void bind_ShapeAnalysis_Curve(py::module &);
void bind_ShapeAnalysis_Edge(py::module &);
void bind_ShapeAnalysis_FreeBoundData(py::module &);
void bind_ShapeAnalysis_FreeBounds(py::module &);
void bind_ShapeAnalysis_SequenceOfFreeBounds(py::module &);
void bind_ShapeAnalysis_HSequenceOfFreeBounds(py::module &);
void bind_ShapeAnalysis_FreeBoundsProperties(py::module &);
void bind_ShapeAnalysis_Geom(py::module &);
void bind_ShapeAnalysis_ShapeContents(py::module &);
void bind_ShapeAnalysis_ShapeTolerance(py::module &);
void bind_ShapeAnalysis_Shell(py::module &);
void bind_ShapeAnalysis_Surface(py::module &);
void bind_ShapeAnalysis_TransferParameters(py::module &);
void bind_ShapeAnalysis_TransferParametersProj(py::module &);
void bind_ShapeAnalysis_Wire(py::module &);
void bind_ShapeAnalysis_WireOrder(py::module &);
void bind_ShapeAnalysis_WireVertex(py::module &);

PYBIND11_MODULE(ShapeAnalysis, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.IntRes2d");

bind_ShapeAnalysis(mod);
bind_ShapeAnalysis_BoxBndTree(mod);
bind_ShapeAnalysis_BoxBndTreeSelector(mod);
bind_ShapeAnalysis_DataMapOfShapeListOfReal(mod);
bind_ShapeAnalysis_DataMapIteratorOfDataMapOfShapeListOfReal(mod);
bind_ShapeAnalysis_CheckSmallFace(mod);
bind_ShapeAnalysis_Curve(mod);
bind_ShapeAnalysis_Edge(mod);
bind_ShapeAnalysis_FreeBoundData(mod);
bind_ShapeAnalysis_FreeBounds(mod);
bind_ShapeAnalysis_SequenceOfFreeBounds(mod);
bind_ShapeAnalysis_HSequenceOfFreeBounds(mod);
bind_ShapeAnalysis_FreeBoundsProperties(mod);
bind_ShapeAnalysis_Geom(mod);
bind_ShapeAnalysis_ShapeContents(mod);
bind_ShapeAnalysis_ShapeTolerance(mod);
bind_ShapeAnalysis_Shell(mod);
bind_ShapeAnalysis_Surface(mod);
bind_ShapeAnalysis_TransferParameters(mod);
bind_ShapeAnalysis_TransferParametersProj(mod);
bind_ShapeAnalysis_Wire(mod);
bind_ShapeAnalysis_WireOrder(mod);
bind_ShapeAnalysis_WireVertex(mod);

}
