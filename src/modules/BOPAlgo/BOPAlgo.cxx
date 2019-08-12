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

void bind_BOPAlgo_Operation(py::module &);
void bind_BOPAlgo_CheckStatus(py::module &);
void bind_BOPAlgo_GlueEnum(py::module &);
void bind_BOPAlgo_AlertBOPNotAllowed(py::module &);
void bind_BOPAlgo_AlertBOPNotSet(py::module &);
void bind_BOPAlgo_AlertBuilderFailed(py::module &);
void bind_BOPAlgo_AlertIntersectionFailed(py::module &);
void bind_BOPAlgo_AlertMultipleArguments(py::module &);
void bind_BOPAlgo_AlertNoFiller(py::module &);
void bind_BOPAlgo_AlertNullInputShapes(py::module &);
void bind_BOPAlgo_AlertPostTreatFF(py::module &);
void bind_BOPAlgo_AlertSolidBuilderFailed(py::module &);
void bind_BOPAlgo_AlertTooFewArguments(py::module &);
void bind_BOPAlgo_AlertBadPositioning(py::module &);
void bind_BOPAlgo_AlertEmptyShape(py::module &);
void bind_BOPAlgo_AlertNotSplittableEdge(py::module &);
void bind_BOPAlgo_AlertRemovalOfIBForEdgesFailed(py::module &);
void bind_BOPAlgo_AlertRemovalOfIBForFacesFailed(py::module &);
void bind_BOPAlgo_AlertRemovalOfIBForMDimShapes(py::module &);
void bind_BOPAlgo_AlertRemovalOfIBForSolidsFailed(py::module &);
void bind_BOPAlgo_AlertSelfInterferingShape(py::module &);
void bind_BOPAlgo_AlertShellSplitterFailed(py::module &);
void bind_BOPAlgo_AlertTooSmallEdge(py::module &);
void bind_BOPAlgo_AlertIntersectionOfPairOfShapesFailed(py::module &);
void bind_BOPAlgo_AlertBuildingPCurveFailed(py::module &);
void bind_BOPAlgo_AlertAcquiredSelfIntersection(py::module &);
void bind_BOPAlgo_AlertUnsupportedType(py::module &);
void bind_BOPAlgo_AlertNoFacesToRemove(py::module &);
void bind_BOPAlgo_AlertUnableToRemoveTheFeature(py::module &);
void bind_BOPAlgo_AlertRemoveFeaturesFailed(py::module &);
void bind_BOPAlgo_AlertSolidBuilderUnusedFaces(py::module &);
void bind_BOPAlgo_AlertUnableToOrientTheShape(py::module &);
void bind_BOPAlgo_Options(py::module &);
void bind_BOPAlgo_Algo(py::module &);
void bind_BOPAlgo_CheckResult(py::module &);
void bind_BOPAlgo_ListOfCheckResult(py::module &);
void bind_BOPAlgo_ListIteratorOfListOfCheckResult(py::module &);
void bind_BOPAlgo_ArgumentAnalyzer(py::module &);
void bind_BOPAlgo_PPaveFiller(py::module &);
void bind_BOPAlgo_BuilderShape(py::module &);
void bind_BOPAlgo_Builder(py::module &);
void bind_BOPAlgo_ToolsProvider(py::module &);
void bind_BOPAlgo_BOP(py::module &);
void bind_BOPAlgo_BuilderArea(py::module &);
void bind_BOPAlgo_BuilderFace(py::module &);
void bind_BOPAlgo_BuilderSolid(py::module &);
void bind_BOPAlgo_CellsBuilder(py::module &);
void bind_BOPAlgo_SectionAttribute(py::module &);
void bind_BOPAlgo_PaveFiller(py::module &);
void bind_BOPAlgo_CheckerSI(py::module &);
void bind_BOPAlgo_MakerVolume(py::module &);
void bind_BOPAlgo_PArgumentAnalyzer(py::module &);
void bind_BOPAlgo_PBOP(py::module &);
void bind_BOPAlgo_PBuilder(py::module &);
void bind_BOPAlgo_PSection(py::module &);
void bind_BOPAlgo_PWireEdgeSet(py::module &);
void bind_BOPAlgo_RemoveFeatures(py::module &);
void bind_BOPAlgo_Section(py::module &);
void bind_BOPAlgo_ShellSplitter(py::module &);
void bind_BOPAlgo_Splitter(py::module &);
void bind_BOPAlgo_Tools(py::module &);
void bind_BOPAlgo_WireEdgeSet(py::module &);
void bind_BOPAlgo_WireSplitter(py::module &);
void bind_BOPAlgo_EdgeInfo(py::module &);
void bind_BOPAlgo_ListOfEdgeInfo(py::module &);
void bind_BOPAlgo_ListIteratorOfListOfEdgeInfo(py::module &);
void bind_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo(py::module &);

PYBIND11_MODULE(BOPAlgo, mod) {

py::module::import("OCCT.Message");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BOPDS");
py::module::import("OCCT.IntTools");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.BOPTools");

bind_BOPAlgo_Operation(mod);
bind_BOPAlgo_CheckStatus(mod);
bind_BOPAlgo_GlueEnum(mod);
bind_BOPAlgo_AlertBOPNotAllowed(mod);
bind_BOPAlgo_AlertBOPNotSet(mod);
bind_BOPAlgo_AlertBuilderFailed(mod);
bind_BOPAlgo_AlertIntersectionFailed(mod);
bind_BOPAlgo_AlertMultipleArguments(mod);
bind_BOPAlgo_AlertNoFiller(mod);
bind_BOPAlgo_AlertNullInputShapes(mod);
bind_BOPAlgo_AlertPostTreatFF(mod);
bind_BOPAlgo_AlertSolidBuilderFailed(mod);
bind_BOPAlgo_AlertTooFewArguments(mod);
bind_BOPAlgo_AlertBadPositioning(mod);
bind_BOPAlgo_AlertEmptyShape(mod);
bind_BOPAlgo_AlertNotSplittableEdge(mod);
bind_BOPAlgo_AlertRemovalOfIBForEdgesFailed(mod);
bind_BOPAlgo_AlertRemovalOfIBForFacesFailed(mod);
bind_BOPAlgo_AlertRemovalOfIBForMDimShapes(mod);
bind_BOPAlgo_AlertRemovalOfIBForSolidsFailed(mod);
bind_BOPAlgo_AlertSelfInterferingShape(mod);
bind_BOPAlgo_AlertShellSplitterFailed(mod);
bind_BOPAlgo_AlertTooSmallEdge(mod);
bind_BOPAlgo_AlertIntersectionOfPairOfShapesFailed(mod);
bind_BOPAlgo_AlertBuildingPCurveFailed(mod);
bind_BOPAlgo_AlertAcquiredSelfIntersection(mod);
bind_BOPAlgo_AlertUnsupportedType(mod);
bind_BOPAlgo_AlertNoFacesToRemove(mod);
bind_BOPAlgo_AlertUnableToRemoveTheFeature(mod);
bind_BOPAlgo_AlertRemoveFeaturesFailed(mod);
bind_BOPAlgo_AlertSolidBuilderUnusedFaces(mod);
bind_BOPAlgo_AlertUnableToOrientTheShape(mod);
bind_BOPAlgo_Options(mod);
bind_BOPAlgo_Algo(mod);
bind_BOPAlgo_CheckResult(mod);
bind_BOPAlgo_ListOfCheckResult(mod);
bind_BOPAlgo_ListIteratorOfListOfCheckResult(mod);
bind_BOPAlgo_ArgumentAnalyzer(mod);
bind_BOPAlgo_PPaveFiller(mod);
bind_BOPAlgo_BuilderShape(mod);
bind_BOPAlgo_Builder(mod);
bind_BOPAlgo_ToolsProvider(mod);
bind_BOPAlgo_BOP(mod);
bind_BOPAlgo_BuilderArea(mod);
bind_BOPAlgo_BuilderFace(mod);
bind_BOPAlgo_BuilderSolid(mod);
bind_BOPAlgo_CellsBuilder(mod);
bind_BOPAlgo_SectionAttribute(mod);
bind_BOPAlgo_PaveFiller(mod);
bind_BOPAlgo_CheckerSI(mod);
bind_BOPAlgo_MakerVolume(mod);
bind_BOPAlgo_PArgumentAnalyzer(mod);
bind_BOPAlgo_PBOP(mod);
bind_BOPAlgo_PBuilder(mod);
bind_BOPAlgo_PSection(mod);
bind_BOPAlgo_PWireEdgeSet(mod);
bind_BOPAlgo_RemoveFeatures(mod);
bind_BOPAlgo_Section(mod);
bind_BOPAlgo_ShellSplitter(mod);
bind_BOPAlgo_Splitter(mod);
bind_BOPAlgo_Tools(mod);
bind_BOPAlgo_WireEdgeSet(mod);
bind_BOPAlgo_WireSplitter(mod);
bind_BOPAlgo_EdgeInfo(mod);
bind_BOPAlgo_ListOfEdgeInfo(mod);
bind_BOPAlgo_ListIteratorOfListOfEdgeInfo(mod);
bind_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo(mod);

}
