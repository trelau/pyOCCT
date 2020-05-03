# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC
# Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest

from OCCT.Graphic3d import (Graphic3d_RenderingParams, Graphic3d_RenderingMode,
                            Graphic3d_RenderTransparentMethod,
                            Graphic3d_ToneMappingMethod, Graphic3d_StereoMode,
                            Graphic3d_Mat4)


class Test_Graphic3d_RenderingParams(unittest.TestCase):
    """
    Tests for Graphic3d_RenderingParams class.
    """

    @classmethod
    def setUpClass(cls):
        cls.p = Graphic3d_RenderingParams()

    def test_ResolutionRatio(self):
        self.assertAlmostEqual(self.p.ResolutionRatio(), 1.)

    def test_Method(self):
        self.assertEqual(self.p.Method,
                         Graphic3d_RenderingMode.Graphic3d_RM_RASTERIZATION)
        self.p.Method = Graphic3d_RenderingMode.Graphic3d_RM_RAYTRACING
        self.assertEqual(self.p.Method,
                         Graphic3d_RenderingMode.Graphic3d_RM_RAYTRACING)

    def test_TransparencyField(self):
        self.assertEqual(self.p.TransparencyMethod,
                         Graphic3d_RenderTransparentMethod.Graphic3d_RTM_BLEND_UNORDERED)
        self.p.TransparencyMethod = Graphic3d_RenderTransparentMethod.Graphic3d_RTM_BLEND_OIT
        self.assertEqual(self.p.TransparencyMethod,
                         Graphic3d_RenderTransparentMethod.Graphic3d_RTM_BLEND_OIT)

    def test_OitDepthFactor(self):
        self.assertAlmostEqual(self.p.OitDepthFactor, 0.)
        self.p.OitDepthFactor = 1.
        self.assertAlmostEqual(self.p.OitDepthFactor, 1.)

    def test_NbMsaaSamples(self):
        self.assertEqual(self.p.NbMsaaSamples, 0)

    def test_RenderResolutionScale(self):
        self.assertAlmostEqual(self.p.RenderResolutionScale, 1.)

    def test_IsGlobalIlluminationEnabled(self):
        self.assertEqual(self.p.IsGlobalIlluminationEnabled, False)
        self.p.IsGlobalIlluminationEnabled = True
        self.assertEqual(self.p.IsGlobalIlluminationEnabled, True)

    def test_RaytracingDepth(self):
        self.assertEqual(self.p.RaytracingDepth, 3)

    def test_IsShadowEnabled(self):
        self.assertEqual(self.p.IsShadowEnabled, True)

    def test_IsReflectionEnabled(self):
        self.assertEqual(self.p.IsReflectionEnabled, False)

    def test_IsAntialiasingEnabled(self):
        self.assertEqual(self.p.IsAntialiasingEnabled, False)

    def test_TransparentShadowEnabled(self):
        self.assertEqual(self.p.IsTransparentShadowEnabled, False)

    def test_UseEnvironmentMapBackground(self):
        self.assertEqual(self.p.UseEnvironmentMapBackground, False)

    def test_CoherentPathTracingMode(self):
        self.assertEqual(self.p.CoherentPathTracingMode, False)

    def test_AdaptiveScreenSampling(self):
        self.assertEqual(self.p.AdaptiveScreenSampling, False)

    def test_ShowSamplingTiles(self):
        self.assertEqual(self.p.ShowSamplingTiles, False)

    def test_TwoSidedBsdfModels(self):
        self.assertEqual(self.p.TwoSidedBsdfModels, False)

    def test_RadianceClampingValue(self):
        self.assertAlmostEqual(self.p.RadianceClampingValue, 30.)

    def test_NbRayTracingTiles(self):
        self.assertEqual(self.p.NbRayTracingTiles, 256)

    def test_CameraApertureRadius(self):
        self.assertAlmostEqual(self.p.CameraApertureRadius, 0.)

    def test_CameraFocalPlaneDist(self):
        self.assertAlmostEqual(self.p.CameraFocalPlaneDist, 1.)

    def test_ToneMappingMethod(self):
        self.assertEqual(self.p.ToneMappingMethod,
                         Graphic3d_ToneMappingMethod.Graphic3d_ToneMappingMethod_Disabled)

    def test_Exposure(self):
        self.assertAlmostEqual(self.p.Exposure, 0.)

    def test_WhitePoint(self):
        self.assertAlmostEqual(self.p.WhitePoint, 1.)

    def test_StereoMode(self):
        self.assertEqual(self.p.StereoMode,
                         Graphic3d_StereoMode.Graphic3d_StereoMode_QuadBuffer)

    def test_AnaglyphFilter(self):
        self.assertEqual(self.p.AnaglyphFilter,
                         self.p.Anaglyph_RedCyan_Optimized)

    def test_AnaglyphLeft(self):
        self.assertIsInstance(self.p.AnaglyphLeft, Graphic3d_Mat4)

    def test_AnaglyphRight(self):
        self.assertIsInstance(self.p.AnaglyphRight, Graphic3d_Mat4)

    def test_ToReverseStereo(self):
        self.assertEqual(self.p.ToReverseStereo, False)

    def test_Resolution(self):
        self.assertEqual(self.p.Resolution, 72)


if __name__ == '__main__':
    unittest.main()
